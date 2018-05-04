import ctypes

# _mod = ctypes.cdll.LoadLibrary('./Sample/Release/Sample.dll')
_mod = ctypes.CDLL('./Sample/Release/Sample.dll')

gcd = _mod.gcd
gcd.argtypes = (ctypes.c_int, ctypes.c_int)
gcd.restype = ctypes.c_int

in_mandel = _mod.in_mandel
in_mandel.argtypes = (ctypes.c_double, ctypes.c_double, ctypes.c_double)
in_mandel.restype = ctypes.c_int

_divide = _mod.divide
_divide.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_divide.restype = ctypes.c_int

def divide(x, y):
    rem = ctypes.c_int()
    qout = _divide(x, y, rem)
    return qout, rem.value

class DoubleArrayType:
    def from_param(self, param):
        typename = type(param).__name__
        print('from_param: {0}, typename: {1}'.format(param, typename))
        if hasattr(self, 'from_' + typename):
            return getattr(self, 'from_' + typename)(param)
        elif isinstance(param, ctypes.Array):
            return param
        else:
            raise TypeError("Can't convert {0}".format(typename))

    def from_array(self, param):
        if param.typecode != 'd':
            raise TypeError('must be an array of doubles')
        ptr, _ = param.buffer_info()
        return ctypes.cast(ptr, ctypes.POINTER(ctypes.c_double))

    def from_list(self, param):
        val = ((ctypes.c_double)*len(param))(*param)
        return val

    from_tuple = from_list

    def from_ndarray(self, param):
        return param.ctypes.data_as(ctypes.POINTER(ctypes.c_double))

DoubleArray = DoubleArrayType()
_avg = _mod.avg
_avg.argtypes = (DoubleArray, ctypes.c_int)
_avg.restype = ctypes.c_double

def avg(values):
    return _avg(values, len(values))

def main():
    print(gcd(35, 42))
    print(in_mandel(0, 0, 500))
    print(in_mandel(2.0, 1.0, 500))
    print(divide(42, 8))
    print(avg((1, 2, 3)))

if __name__ == '__main__':
    main()
