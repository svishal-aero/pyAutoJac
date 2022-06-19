import ctypes as C

import sys

sys.path.insert(0, "/home/svishal/Git/pyJacADF/Variable")
from Variable import Variable
sys.path.pop(0)

lib = C.CDLL("/home/svishal/Git/pyJacADF/Jacobian/libJacobian.so")

class Jacobian(C.Structure):

    _pack_ = 1
    _fields_ = [
        ("input", C.POINTER(Variable)),
        ("output", C.POINTER(Variable)),
        ("nRows", C.c_int),
        ("offsets", C.POINTER(C.c_int)),
        ("columns", C.POINTER(C.c_int)),
        ("entries", C.POINTER(C.c_double)),
    ]

    _init = lib.Jacobian__init
    _init.restype = None
    _init.argtypes = [
        C.c_void_p,
    ]

    _create = lib.Jacobian__create
    _create.restype = None
    _create.argtypes = [
        C.c_void_p,
        C.POINTER(Variable),
        C.POINTER(Variable),
    ]

    _evaluate = lib.Jacobian__evaluate
    _evaluate.restype = None
    _evaluate.argtypes = [
        C.c_void_p,
    ]

    _delete = lib.Jacobian__delete
    _delete.restype = None
    _delete.argtypes = [
        C.c_void_p,
    ]

    def __init__(
        self,
    ):
        return self._init(
            C.addressof(self),
        )

    def create(
        self,
        output,
        input,
    ):
        return self._create(
            C.addressof(self),
            output,
            input,
        )

    def evaluate(
        self,
    ):
        return self._evaluate(
            C.addressof(self),
        )

    def delete(
        self,
    ):
        return self._delete(
            C.addressof(self),
        )

