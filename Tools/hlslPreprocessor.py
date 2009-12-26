import sys
from pyparsing import *
ParserElement.enablePackrat()

hlslIdentifier = Regex(r'[a-zA-Z_][a-zA-Z0-9_]*')

hlslPPInclude = \
Group(
    Keyword('#include') + 
    (
        (Suppress('<') + SkipTo('>') + Suppress('>')) | 
        dblQuotedString
    )
)

hlslPPIf = \
Group(
    Keyword('#if') + SkipTo(LineEnd()) +
    Optional(
        SkipTo('#else') + 
        Keyword('#else')
    ) + 
    SkipTo('#endif') + 
    Keyword('#endif')
)

hlslPPIfdef = \
Group(
    Keyword('#ifdef') + SkipTo(LineEnd()) +
    Optional(
        SkipTo('#else') + 
        Keyword('#else')
    ) + 
    SkipTo('#endif') + 
    Keyword('#endif')
)

hlslPPDefine = Group(Keyword('#define') + hlslIdentifier + SkipTo(lineEnd))

hlslPPTokens = (hlslPPInclude | hlslPPIf | hlslPPIfdef | hlslPPDefine)
hlslPPTokens = hlslPPInclude
hlslComment = cppStyleComment

hlslPPFile = SkipTo(LineStart() + Literal('#')) + ZeroOrMore(hlslPPTokens + SkipTo(LineStart() + Literal('#'))) + StringEnd()
hlslPPFile.ignore(hlslComment)

def preprocess(string):
    try:
        return hlslPPFile.transformString(string)
    except ParseException, pe:
        print "Parsing failed"
        print pe.markInputline()
        print pe.lineno, pe.column, pe.msg

if __name__=='__main__':
    print preprocess(file(sys.argv[1], 'r').read())
