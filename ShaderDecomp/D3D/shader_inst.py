NOP = 0
MOV = 1
ADD = 2
SUB = 3
MAD = 4
MUL = 5
RCP = 6
RSQ = 7
DP3 = 8
DP4 = 9
MIN = 10
MAX = 11
SLT = 12
SGE = 13
EXP = 14
LOG = 15
LIT = 16
DST = 17
LRP = 18
FRC = 19
M4x4 = 20
M4x3 = 21
M3x4 = 22
M3x3 = 23
M3x2 = 24
CALL = 25
CALLNZ = 26
LOOP = 27
RET = 28
ENDLOOP = 29
LABEL = 30
DCL = 31
POW = 32
CRS = 33
SGN = 34
ABS = 35
NRM = 36
SINCOS = 37
REP = 38
ENDREP = 39
IF = 40
IFC = 41
ELSE = 42
ENDIF = 43
BREAK = 44
BREAKC = 45
MOVA = 46
DEFB = 47
DEFI = 48
TEXCOORD = 49
TEXKILL = 50
TEX = 51
TEXBEM = 52
TEXBEML = 53
TEXREG2AR = 54
TEXREG2GB = 55
TEXM3x2PAD = 56
TEXM3x2TEX = 57
TEXM3x3PAD = 58
TEXM3x3TEX = 59
RESERVED0 = 60
TEXM3x3SPEC = 61
TEXM3x3VSPEC = 62
EXPP = 63
LOGP = 64
CND = 65
DEF = 66
TEXREG2RGB = 67
TEXDP3TEX = 68
TEXM3x2DEPTH = 69
TEXDP3 = 70
TEXM3x3 = 71
TEXDEPTH = 72
CMP = 73
BEM = 74
DP2ADD = 75
DSX = 76
DSY = 77
TEXLDD = 78
SETP = 79
TEXLDL = 80
BREAKP = 81
PHASE = 0xFFFD
COMMENT = 0xFFFE
END = 0xFFFF

SOURCE = 0x10000
DEST = 0x20000
LABEL = 0x30000
CUSTOM = 0x40000
VARARGS = 0x50000

string_map = {}
string_map[NOP] = 'NOP'
string_map[MOV] = 'MOV'
string_map[ADD] = 'ADD'
string_map[SUB] = 'SUB'
string_map[MAD] = 'MAD'
string_map[MUL] = 'MUL'
string_map[RCP] = 'RCP'
string_map[RSQ] = 'RSQ'
string_map[DP3] = 'DP3'
string_map[DP4] = 'DP4'
string_map[MIN] = 'MIN'
string_map[MAX] = 'MAX'
string_map[SLT] = 'SLT'
string_map[SGE] = 'SGE'
string_map[EXP] = 'EXP'
string_map[LOG] = 'LOG'
string_map[LIT] = 'LIT'
string_map[DST] = 'DST'
string_map[LRP] = 'LRP'
string_map[FRC] = 'FRC'
string_map[M4x4] = 'M4x4'
string_map[M4x3] = 'M4x3'
string_map[M3x4] = 'M3x4'
string_map[M3x3] = 'M3x3'
string_map[M3x2] = 'M3x2'
string_map[CALL] = 'CALL'
string_map[CALLNZ] = 'CALLNZ'
string_map[LOOP] = 'LOOP'
string_map[RET] = 'RET'
string_map[ENDLOOP] = 'ENDLOOP'
string_map[LABEL] = 'LABEL'
string_map[DCL] = 'DCL'
string_map[POW] = 'POW'
string_map[CRS] = 'CRS'
string_map[SGN] = 'SGN'
string_map[ABS] = 'ABS'
string_map[NRM] = 'NRM'
string_map[SINCOS] = 'SINCOS'
string_map[REP] = 'REP'
string_map[ENDREP] = 'ENDREP'
string_map[IF] = 'IF'
string_map[IFC] = 'IFC'
string_map[ELSE] = 'ELSE'
string_map[ENDIF] = 'ENDIF'
string_map[BREAK] = 'BREAK'
string_map[BREAKC] = 'BREAKC'
string_map[MOVA] = 'MOVA'
string_map[DEFB] = 'DEFB'
string_map[DEFI] = 'DEFI'
string_map[TEXCOORD] = 'TEXCOORD'
string_map[TEXKILL] = 'TEXKILL'
string_map[TEX] = 'TEX'
string_map[TEXBEM] = 'TEXBEM'
string_map[TEXBEML] = 'TEXBEML'
string_map[TEXREG2AR] = 'TEXREG2AR'
string_map[TEXREG2GB] = 'TEXREG2GB'
string_map[TEXM3x2PAD] = 'TEXM3x2PAD'
string_map[TEXM3x2TEX] = 'TEXM3x2TEX'
string_map[TEXM3x3PAD] = 'TEXM3x3PAD'
string_map[TEXM3x3TEX] = 'TEXM3x3TEX'
string_map[RESERVED0] = 'RESERVED0'
string_map[TEXM3x3SPEC] = 'TEXM3x3SPEC'
string_map[TEXM3x3VSPEC] = 'TEXM3x3VSPEC'
string_map[EXPP] = 'EXPP'
string_map[LOGP] = 'LOGP'
string_map[CND] = 'CND'
string_map[DEF] = 'DEF'
string_map[TEXREG2RGB] = 'TEXREG2RGB'
string_map[TEXDP3TEX] = 'TEXDP3TEX'
string_map[TEXM3x2DEPTH] = 'TEXM3x2DEPTH'
string_map[TEXDP3] = 'TEXDP3'
string_map[TEXM3x3] = 'TEXM3x3'
string_map[TEXDEPTH] = 'TEXDEPTH'
string_map[CMP] = 'CMP'
string_map[BEM] = 'BEM'
string_map[DP2ADD] = 'DP2ADD'
string_map[DSX] = 'DSX'
string_map[DSY] = 'DSY'
string_map[TEXLDD] = 'TEXLDD'
string_map[SETP] = 'SETP'
string_map[TEXLDL] = 'TEXLDL'
string_map[BREAKP] = 'BREAKP'
string_map[PHASE] = 'PHASE'
string_map[COMMENT] = 'COMMENT'
string_map[END] = 'END'

instructions = []
app = lambda *args: instructions.append(*args)
app((ABS, DEST, SOURCE))
app((ADD, DEST, SOURCE, SOURCE))
app((BEM, DEST, SOURCE, SOURCE))
app((BREAK, ))
app((BREAKC, SOURCE, SOURCE))
app((BREAKP, SOURCE))
app((CALL, LABEL))
app((CALLNZ, LABEL, SOURCE))
app((CMP, DEST, SOURCE, SOURCE, SOURCE))
app((CND, DEST, SOURCE, SOURCE, SOURCE))
app((CRS, DEST, SOURCE, SOURCE))
app((DCL, CUSTOM, DEST))
app((DEF, DEST, CUSTOM, CUSTOM, CUSTOM, CUSTOM))
app((DEFB, DEST, CUSTOM))
app((DEFI, DEST, CUSTOM, CUSTOM, CUSTOM, CUSTOM))
app((DP2ADD, DEST, SOURCE, SOURCE))
app((DP3, DEST, SOURCE, SOURCE))
app((DP4, DEST, SOURCE, SOURCE))
app((DST, DEST, SOURCE, SOURCE))
app((DSX, DEST, SOURCE))
app((DSY, DEST, SOURCE))
app((ELSE, ))
app((ENDIF, ))
app((ENDLOOP, ))
app((ENDREP, ))
app((EXP, DEST, SOURCE))
app((EXPP, DEST, SOURCE))
app((FRC, DEST, SOURCE))
app((IF, SOURCE))
app((IFC, SOURCE, SOURCE))
app((LIT, DEST, SOURCE))
app((LOG, DEST, SOURCE))
app((LOGP, DEST, SOURCE))
app((LOOP, SOURCE, SOURCE))
app((LRP, DEST, SOURCE, SOURCE, SOURCE))
app((M3x2, DEST, SOURCE, SOURCE))
app((M3x3, DEST, SOURCE, SOURCE))
app((M3x4, DEST, SOURCE, SOURCE))
app((M4x3, DEST, SOURCE, SOURCE))
app((MAD, DEST, SOURCE, SOURCE, SOURCE))
app((MAX, DEST, SOURCE, SOURCE))
app((MIN, DEST, SOURCE, SOURCE))
app((MOV, DEST, SOURCE))
app((MOVA, DEST, SOURCE))
app((MUL, DEST, SOURCE, SOURCE))
app((NRM, DEST, SOURCE))
app((PHASE, ))
app((POW, DEST, SOURCE, SOURCE))
app((RCP, DEST, SOURCE))
app((REP, SOURCE))
app((RET, ))
app((RSQ, DEST, SOURCE))
app((SETP, DEST, SOURCE, SOURCE))
app((SGE, DEST, SOURCE, SOURCE))
app((SGN, DEST, SOURCE, SOURCE, SOURCE))
app((SINCOS, VARARGS))
app((SLT, DEST, SOURCE, SOURCE))
app((SUB, DEST, SOURCE, SOURCE))
app((TEX, VARARGS))
app((TEXBEM, DEST, SOURCE))
app((TEXBEML, DEST, SOURCE))
app((TEXCOORD, VARARGS))
app((TEXDEPTH, DEST))
app((TEXDP3, DEST, SOURCE))
app((TEXDP3TEX, DEST, SOURCE))
app((TEXKILL, DEST))
app((TEXLDD, DEST, SOURCE, SOURCE, SOURCE, SOURCE))
app((TEXLDL, DEST, SOURCE, SOURCE))
app((TEXM3x2DEPTH, DEST, SOURCE))
app((TEXM3x2PAD, DEST, SOURCE))
app((TEXM3x2TEX, DEST, SOURCE))
app((TEXM3x3, DEST, SOURCE))
app((TEXM3x3PAD, DEST, SOURCE))
app((TEXM3x3SPEC, DEST, SOURCE, SOURCE))
app((TEXM3x3TEX, DEST, SOURCE))
app((TEXM3x3VSPEC, DEST, SOURCE))
app((TEXREG2AR, DEST, SOURCE))
app((TEXREG2GB, DEST, SOURCE))
app((TEXREG2RGB, DEST, SOURCE))
app((COMMENT, VARARGS))
app((END, ))
