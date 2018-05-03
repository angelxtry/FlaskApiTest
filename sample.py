import ctypes
from double_array_type import DoubleArrayType

_mod = ctypes.CDLL('./ExternCTest/Release/ExternCTest.dll')

gcd = _mod.gcd
gcd.argtypes = (ctypes.c_int, ctypes.c_int)
gcd.restype = ctypes.c_int
print(gcd(35, 42))

DoubleArray = DoubleArrayType()

bs0 = _mod.BSOption0
bs0.argtypes = (ctypes.c_int, ctypes.c_double)
bs0.restype = ctypes.c_short

bs1 = _mod.BSOption1
bs1.argtypes = (ctypes.c_int, ctypes.c_double, DoubleArray)
bs1.restype = ctypes.POINTER(ctypes.c_double)

TypeFlag = 1
S0 = 1.000000
t = [0.250000]
print(bs0(TypeFlag, S0))
print(bs1(TypeFlag, S0, t))

BSOption_Delta = _mod.BSOption_Delta
BSOption_Delta.argtypes = (
                  ctypes.c_short,
                  ctypes.c_double,
                  DoubleArray,
                  DoubleArray,
                  ctypes.c_short,
                  DoubleArray,
                  DoubleArray,
                  ctypes.c_short,
                  DoubleArray,
                  DoubleArray,
                  ctypes.c_short,
                  ctypes.c_double,
                  ctypes.c_double,
                  ctypes.c_short,
                  ctypes.c_short,
                  ctypes.c_short
                  )
BSOption_Delta.restype = ctypes.c_double

TypeFlag = 1
S0 = 1.000000
t = [0.250000]
rf = [0.050800]
nt = 1
td = [0.250000]
rd = [0.050800]
ntd = 1
t_vol = [0.083333]
vol = [0.244500]
n_vol = 1
dvd = 0.017520
X = 1.000000
MaturityDate = 395
PaymentDate = 400
TextFlag = 0

print(BSOption_Delta(TypeFlag, 
    S0,
    t,
    rf,
    nt,
    td,
    rd,
    ntd,
    t_vol,
    vol,
    n_vol,
    dvd,
    X,
    MaturityDate,
    PaymentDate,
    TextFlag
    ))
