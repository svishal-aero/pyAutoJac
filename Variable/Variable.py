import ctypes as C

import sys

sys.path.insert(0, "/home/svishal/Git/pyJacADF/DepVarList")
from DepVarList import DepVarList
sys.path.pop(0)

lib = C.CDLL("/home/svishal/Git/pyJacADF/Variable/libVariable.so")

class Variable(C.Structure):

    _pack_ = 1
    _fields_ = [
        ("size", C.c_int),
        ("nElems", C.c_int),
        ("elemSize", C.c_int),
        ("data", C.POINTER(C.c_double)),
        ("calcFlag", C.c_int),
        ("", None),
        ("depVarList", DepVarList),
    ]

    _init = lib.Variable__init
    _init.restype = None
    _init.argtypes = [
        C.c_void_p,
    ]

    _delete = lib.Variable__delete
    _delete.restype = None
    _delete.argtypes = [
        C.c_void_p,
    ]

    _create = lib.Variable__create
    _create.restype = None
    _create.argtypes = [
        C.c_void_p,
        C.c_int,
        C.c_int,
    ]

    _addDepVar = lib.Variable__addDepVar
    _addDepVar.restype = None
    _addDepVar.argtypes = [
        C.c_void_p,
        C.c_void_p,
        C.POINTER(C.c_int),
        C.POINTER(C.c_double),
    ]

    _calculate = lib.Variable__calculate
    _calculate.restype = None
    _calculate.argtypes = [
        C.c_void_p,
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
        nElems,
        elemSize,
    ):
        return self._create(
            C.addressof(self),
            nElems,
            elemSize,
        )

    def addDepVar(
        self,
        variable,
        indices,
        sens,
    ):
        return self._addDepVar(
            C.addressof(self),
            C.addressof(variable),
            indices,
            sens,
        )

    def calculate(
        self,
    ):
        return self._calculate(
            C.addressof(self),
        )

