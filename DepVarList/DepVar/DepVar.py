import ctypes as C

lib = C.CDLL("/home/svishal/Git/pyJacADF/DepVarList/DepVar/libDepVar.so")

class DepVar(C.Structure):

    _pack_ = 1
    _fields_ = [
        ("prev", C.c_void_p),
        ("next", C.c_void_p),
        ("variable", C.c_void_p),
        ("indices", C.POINTER(C.c_int)),
        ("sens", C.POINTER(C.c_double)),
        ("sensFlag", C.c_int),
    ]

    _init = lib.DepVar__init
    _init.restype = None
    _init.argtypes = [
        C.c_void_p,
    ]

    _delete = lib.DepVar__delete
    _delete.restype = None
    _delete.argtypes = [
        C.c_void_p,
    ]

    _create = lib.DepVar__create
    _create.restype = None
    _create.argtypes = [
        C.c_void_p,
        C.c_int,
        C.c_int,
        C.c_int,
        C.c_void_p,
        C.POINTER(C.c_int),
        C.POINTER(C.c_double),
    ]

    def __init__(
        self,
    ):
        return self._init(
            C.addressof(self),
        )

    def delete(
        self,
    ):
        return self._delete(
            C.addressof(self),
        )

    def create(
        self,
        nElemsOut,
        elemSizeOut,
        elemSizeIn,
        variable,
        indices,
        sens,
    ):
        return self._create(
            C.addressof(self),
            nElemsOut,
            elemSizeOut,
            elemSizeIn,
            C.addressof(variable),
            indices,
            sens,
        )

