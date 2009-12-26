import sys

from pyparsing import *
ParserElement.enablePackrat()

import hlslPreprocessor

def DelimitedList(expr, delim=',', combine=False):
    return Group(delimitedList(expr, delim=delim, combine=combine) + Optional(Suppress(delim)))

ZeroOrMoreNG = ZeroOrMore
def ZeroOrMore(*args, **kwargs):
    return Group(ZeroOrMoreNG(*args, **kwargs))

OneOrMoreNG = OneOrMore
def OneOrMore(*args, **kwargs):
    return Group(OneOrMoreNG(*args, **kwargs))

def AllButOne(elem, term=None, type=OneOrMore, combine=False):
    if term:
        if combine:
            return Combine(type(elem + FollowedBy(elem | term)), joinString=combine, adjacent=False)
        else:
            return type(elem + FollowedBy(elem | term))
    else:
        if combine:
            return Combine(type(elem + FollowedBy(elem)), joinString=combine, adjacent=False)
        else:
            return type(elem + FollowedBy(elem))

def StateBlock(start, eatSemicolon=True):
    global hlslExpression
    
    hlslStateDecl = \
    Group(
        AllButOne(hlslIdentifier, type=ZeroOrMore, combine=True).setResultsName('stateDeclType') + 
        hlslIdentifier.setResultsName('stateDeclName') + 
        ZeroOrMore(hlslSubscript).setResultsName('stateDeclSubscript') + 
        Optional(
            Suppress('=') + 
            hlslExpression.setResultsName('stateDeclValue')
        ) + 
        Suppress(';')
    ).setResultsName('stateDecl')
    if eatSemicolon:
        return \
        Group(
            start +
            Suppress('{') + 
            ZeroOrMore(hlslStateDecl).setResultsName('stateDeclBody') + 
            Suppress('}') + 
            Optional(Suppress(';'))
        ).setResultsName('stateBlock')
    else:
        return \
        Group(
            start +
            Suppress('{') + 
            ZeroOrMore(hlslStateDecl).setResultsName('stateDeclBody') + 
            Suppress('}')
        ).setResultsName('stateBlock')

filename = sys.argv[1]

code = file(filename).read()

hlslFile = Forward()
hlslStructDefinition = Forward()
hlslExpression = Forward()
hlslNoArithmeticExpr = Forward()
hlslNoComparisonExpr = Forward()
hlslNoLogicalExpr = Forward()
hlslNoTernaryExpr = Forward()
hlslStatement = Forward()
hlslFunctionBody = Forward()
hlslFunctionLine = Forward()

hlslLine = Forward()

hlslComment = cppStyleComment 

hlslIdentifier = Regex(r'[a-zA-Z_][a-zA-Z0-9_]*').setResultsName('identifier')
hlslHexNumber = Regex(r'0x[0-9a-fA-F]+').setResultsName('hexNumber')
hlslNumber = hlslHexNumber ^ Regex(r'-?[0-9]+(\.[0-9]*f?)?').setResultsName('number')
hlslString = QuotedString(quoteChar="\"", escChar='\\', multiline=True).setResultsName('string')
hlslSubscript = Suppress('[') + hlslExpression.setResultsName('subscript') + Suppress(']')
hlslObjectReference = Suppress('.') + hlslExpression.setResultsName('objectReference')
hlslOperand = \
Group(
    hlslIdentifier.setResultsName('operandBase') + 
    OneOrMore(hlslObjectReference ^ hlslSubscript).setResultsName('operandModifiers')
).setResultsName('operand') ^ hlslIdentifier
hlslArray = Group(Suppress('{') + DelimitedList(hlslExpression) + Suppress('}'))
hlslGroup = \
Group(
    Suppress('(') + 
    hlslExpression.setResultsName('groupBody') + 
    Suppress(')')
).setResultsName('group')

hlslVariableDecl = \
Group(
    AllButOne(hlslIdentifier, term='<', combine=True).setResultsName('variableDeclType') +
    Optional(Suppress('<') + hlslIdentifier.setResultsName('variableDeclTemplate') + Suppress('>')) + 
    hlslIdentifier.setResultsName('variableDeclName') + 
    ZeroOrMore(hlslSubscript).setResultsName('variableDeclSubscript') + 
    Optional(OneOrMore(Suppress(':') + hlslIdentifier).setResultsName('variableDeclRegister'))
).setResultsName('variableDecl')
hlslAssignment = \
Group(
    Group(
        hlslVariableDecl ^ 
        hlslOperand ^ 
        hlslIdentifier
    ).setResultsName('assignmentDest') + 
    oneOf('= -= += /= *= %= ^= &= |= <<= >>=').setResultsName('assignmentOp') + 
    hlslExpression.setResultsName('assignmentSrc')
).setResultsName('assignment')

hlslMultiVar = \
(
    hlslIdentifier.setResultsName('multiVarName') + 
    ZeroOrMore(hlslSubscript).setResultsName('multiVarSubscript') + 
    Optional(Suppress('=') + hlslExpression.setResultsName('multiVarValue'))
).setResultsName('multiVar')

hlslMultiVarDecl = \
Group(
    AllButOne(hlslIdentifier, combine=True).setResultsName('multiVarDeclType') + 
    FollowedBy(hlslMultiVar + ',' + hlslMultiVar) + 
    DelimitedList(hlslMultiVar).setResultsName('multiVarDeclPairs')
).setResultsName('multiVarDecl')

hlslStructMember = \
Group(
    AllButOne(hlslIdentifier, combine=True).setResultsName('structMemberType') +
    hlslIdentifier.setResultsName('structMemberName') +
    ZeroOrMore(hlslSubscript).setResultsName('structMemberSubscript') + 
    Optional(Suppress(':') + hlslIdentifier.setResultsName('structMemberRegister')) + 
    Optional(Suppress('=') + hlslExpression.setResultsName('structMemberValue')) + 
    Suppress(';')
).setResultsName('structMember')

hlslStructDefinition << \
Group(
    Keyword('struct') + hlslIdentifier.setResultsName('structName') + 
    Suppress('{') + 
    ZeroOrMore(hlslStructMember).setResultsName('structBody') + 
    Suppress('}') + Suppress(';')
).setResultsName('struct')

hlslFunctionArg = \
Group(
    AllButOne(hlslIdentifier, term='<', combine=True).setResultsName('functionArgType') + 
    Optional(Suppress('<') + hlslIdentifier.setResultsName('functionArgTemplate') + Suppress('>')) + 
    hlslIdentifier.setResultsName('functionArgName') + 
    Optional(OneOrMore(hlslSubscript)).setResultsName('functionArgSubscript') + 
    Optional(OneOrMore(Suppress(':') + hlslIdentifier)).setResultsName('functionArgRegister')
).setResultsName('functionArg')

hlslMaxVertex = Group(Suppress('[') + Keyword('maxvertexcount') + Suppress('(') + hlslNumber.setResultsName('maxVertexCount') + Suppress(')') + Suppress(']'))
hlslFunction = \
Group(
    Optional(hlslMaxVertex) + 
    AllButOne(hlslIdentifier, combine=True).setResultsName('functionType') +
    hlslIdentifier.setResultsName('functionName') + 
    Suppress('(') + Optional(DelimitedList(hlslFunctionArg).setResultsName('functionArgs')) + Suppress(')') + 
    Optional(Suppress(':') + hlslIdentifier.setResultsName('functionRegister')) + 
    Suppress('{') + 
    hlslFunctionBody.setResultsName('functionBody') + 
    Suppress('}')
).setResultsName('function')

hlslSamplerState = StateBlock(Keyword('SamplerState') + hlslIdentifier.setResultsName('stateBlockName')).setResultsName('samplerState')
hlslBlendState = StateBlock(Keyword('BlendState') + hlslIdentifier.setResultsName('stateBlockName')).setResultsName('blendState')
hlslDepthStencilState = StateBlock(Keyword('DepthStencilState') + hlslIdentifier.setResultsName('stateBlockName')).setResultsName('depthStencilState')
hlslRasterizerState = StateBlock(Keyword('RasterizerState') + hlslIdentifier.setResultsName('stateBlockName')).setResultsName('rasterizerState')
hlslCBuffer = StateBlock(Keyword('cbuffer') + hlslIdentifier.setResultsName('bufferName')).setResultsName('cbuffer')
hlslTBuffer = StateBlock(Keyword('tbuffer') + hlslIdentifier.setResultsName('bufferName')).setResultsName('tbuffer')
hlslStateBlock = StateBlock(Keyword('sampler_state') | Keyword('stateblock_state'), eatSemicolon=False).setResultsName('state')

hlslForLoop = \
Group(
    Optional(Suppress('[') + Keyword('unroll') + Suppress(']')) +
    Keyword('for') + Suppress('(') +
    hlslExpression.setResultsName('forLoopInit') + Suppress(';') + 
    hlslExpression.setResultsName('forLoopCheck') + Suppress(';') + 
    hlslExpression.setResultsName('forLoopNext') + Suppress(')') + 
    Group(
        (
            Suppress('{') + 
            hlslFunctionBody + 
            Suppress('}')
        ) ^ 
        hlslFunctionLine
    ).setResultsName('forLoopBody')
).setResultsName('forLoop')

hlslIfStatement = \
Group(
    Optional(Keyword('branch') ^ Keyword('flatten')).setResultsName('ifModifiers') + 
    Keyword('if') + Suppress('(') + 
    hlslExpression.setResultsName('ifCondition') + 
    Suppress(')') +
    Group(
        (
            Suppress('{') + 
            hlslFunctionBody + 
            Suppress('}')
        ) ^ 
        hlslFunctionLine
    ).setResultsName('ifBody') +
    Optional(
        Suppress('else') + 
        Group(
            (
                Suppress('{') + 
                hlslFunctionBody + 
                Suppress('}')
            ) ^ 
            hlslFunctionLine
        ).setResultsName('elseBody')
    ).setResultsName('else')
).setResultsName('if')

hlslPass = \
Group(
    Keyword('pass') + hlslIdentifier.setResultsName('passName') + 
    Suppress('{') + 
    ZeroOrMore(hlslLine).setResultsName('passBody') + 
    Suppress('}')
).setResultsName('pass')

hlslTechnique = \
Group(
    Keyword('technique10') + hlslIdentifier.setResultsName('technique10Name') + 
    Suppress('{') + 
    ZeroOrMore(hlslPass).setResultsName('technique10Body') + 
    Suppress('}') + Optional(Suppress(';'))
).setResultsName('technique10')

hlslFunctionCall = \
Group(
    Group(hlslOperand).setResultsName('functionCallee') + 
    Suppress('(') + 
    Group(Optional(DelimitedList(hlslExpression))).setResultsName('functionCallArgs') + 
    Suppress(')')
).setResultsName('functionCall')

hlslReturnStatement = \
Group(
    Keyword('return') + Optional(hlslExpression).setResultsName('returnValue')
).setResultsName('return')

hlslArithmeticOp = oneOf('- + / * % ^ & | << >>')
hlslArithmetic = \
Group(
    hlslNoArithmeticExpr.setResultsName('arithmeticLeft') + 
    hlslArithmeticOp.setResultsName('arithmeticOp') + 
    hlslExpression.setResultsName('arithmeticRight')
).setResultsName('arithmetic')

hlslPreIncDec = \
Group(
    Group(Literal('--') ^ Literal('++')).setResultsName('preIncDecOp') + 
    Group(hlslOperand ^ hlslIdentifier).setResultsName('preIncDecOperand')
).setResultsName('preIncDec')
hlslPostIncDec = \
Group(
    Group(hlslOperand ^ hlslIdentifier).setResultsName('postIncDecOperand') + 
    Group(Literal('--') ^ Literal('++')).setResultsName('postIncDecOp')
).setResultsName('postIncDec')
hlslNot = \
Group(
    Group(
        (Literal('-') + NotAny('-')) ^ 
        Literal('!') ^ 
        Literal('^')
    ).setResultsName('notOp') + 
    hlslExpression.setResultsName('notOperand')
).setResultsName('not')
hlslUnary = hlslPreIncDec ^ hlslPostIncDec ^ hlslNot

hlslComparison = \
Group(
    hlslNoComparisonExpr.setResultsName('comparisonLeft') + 
    oneOf('<= < >= > == !=').setResultsName('comparisonOp') + 
    hlslExpression.setResultsName('comparisonRight')
).setResultsName('comparison')
hlslLogicalAndOr = \
Group(
    hlslNoLogicalExpr.setResultsName('boolLogicLeft') + 
    oneOf('&& ||').setResultsName('boolLogicOp') + 
    hlslExpression.setResultsName('boolLogicRight')
).setResultsName('boolLogic')
hlslTernary = \
Group(
    hlslNoTernaryExpr.setResultsName('ternaryCondition') + 
    Suppress('?') + hlslExpression.setResultsName('ternaryIf') + 
    ':' + hlslExpression.setResultsName('ternaryElse')
).setResultsName('ternary')

hlslCast = \
Group(
    Suppress('(') + 
    hlslIdentifier.setResultsName('castType') + 
    Suppress(')') + 
    FollowedBy(hlslExpression)
).setResultsName('cast')

hlslCompile = \
Group(
    Keyword('compile') + 
    hlslIdentifier + 
    hlslFunctionCall
)

hlslNoArithmeticExpr << \
Group(
    Optional(hlslCast) + 
    Group(
        (
            hlslFunctionCall | 
            hlslAssignment | 
            hlslOperand | 
            hlslIdentifier | 
            hlslNumber
        ) ^ 
        hlslFunctionCall ^ 
        hlslUnary ^
        hlslArray ^
        hlslGroup ^
        hlslString
    )
)

hlslNoComparisonExpr << \
Group(
    Optional(hlslCast) + 
    Group(
        (
            hlslFunctionCall | 
            hlslAssignment | 
            hlslOperand | 
            hlslIdentifier | 
            hlslNumber
        ) ^ 
        hlslFunctionCall ^ 
        hlslArithmetic ^
        hlslUnary ^
        hlslArray ^
        hlslGroup ^
        hlslString
    ).setResultsName('expr')
)

hlslNoLogicalExpr << \
Group(
    Optional(hlslCast) + 
    Group(
        (
            hlslFunctionCall | 
            hlslAssignment | 
            hlslOperand | 
            hlslIdentifier | 
            hlslNumber
        ) ^ 
        hlslFunctionCall ^ 
        hlslArithmetic ^ 
        hlslUnary ^ 
        hlslComparison ^
        hlslArray ^
        hlslGroup ^
        hlslString
    ).setResultsName('expr')
)

hlslNoTernaryExpr << \
Group(
    Optional(hlslCast) + 
    Group(
        (
            hlslFunctionCall | 
            hlslAssignment | 
            hlslOperand | 
            hlslIdentifier | 
            hlslNumber
        ) ^ 
        hlslFunctionCall ^ 
        hlslArithmetic ^ 
        hlslUnary ^ 
        hlslComparison ^
        hlslArray ^
        hlslGroup ^
        hlslLogicalAndOr ^
        hlslString
    ).setResultsName('expr')
)

hlslAllExpressions = \
(
    (
        hlslFunctionCall | 
        hlslAssignment | 
        hlslOperand | 
        hlslIdentifier | 
        hlslNumber
    ) ^ 
    hlslArithmetic ^ 
    hlslUnary ^ 
    hlslComparison ^
    hlslArray ^
    hlslGroup ^
    hlslLogicalAndOr ^
    hlslTernary ^
    hlslString ^
    hlslStateBlock ^
    hlslCompile
)

hlslExpression << \
Group(
    Optional(hlslCast) + 
    Group(hlslAllExpressions).setResultsName('expr')
)

hlslStatement << \
(
    hlslReturnStatement ^ 
    hlslVariableDecl ^ 
    hlslMultiVarDecl ^ 
    hlslAllExpressions
)
hlslLine << (hlslStatement + Suppress(';'))

hlslBlock = Suppress('{') + hlslFunctionBody + Suppress('}')

hlslFunctionLine << (hlslLine | hlslIfStatement | hlslForLoop | hlslBlock)
hlslFunctionBody << (ZeroOrMore(hlslFunctionLine))

hlslAssignStmt = (hlslAssignment ^ hlslVariableDecl ^ hlslMultiVarDecl) + Suppress(';')

hlslBlock = \
(
    hlslFunction ^ 
    hlslTechnique ^ 
    hlslAssignStmt ^ 
    hlslStructDefinition ^ 
    hlslSamplerState ^ 
    hlslBlendState ^ 
    hlslDepthStencilState ^
    hlslRasterizerState ^
    hlslCBuffer ^
    hlslTBuffer
)

hlslFile << (ZeroOrMore(hlslBlock) + StringEnd())

hlslFile.ignore(hlslComment)
hlslFile.ignore(Keyword('technique') + hlslIdentifier + Suppress('{') + ZeroOrMore(hlslPass) + Suppress('}'))

#hlslFile.validate()

try:
    print hlslFile.parseString(code).asXML()
except ParseException, pe:
    print "Parsing failed"
    print pe.markInputline() 
    print pe.lineno, pe.column, pe.msg
