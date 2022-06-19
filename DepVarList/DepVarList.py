import ctypes as C

import sys

sys.path.insert(0, "/home/svishal/Git/pyJacADF/DepVarList/DepVar")
from DepVar import DepVar
sys.path.pop(0)

lib = C.CDLL("/home/svishal/Git/pyJacADF/DepVarList/libDepVarList.so")

class DepVarList(C.Structure):

    _pack_ = 1
    _fields_ = [
        ("first", C.POINTER(DepVar)),
        ("last", C.POINTER(DepVar)),
    ]

    _init = lib.DepVarList__init
    _init.restype = None
    _init.argtypes = [
        C.c_void_p,
    ]

    _addDepVar = lib.DepVarList__addDepVar
    _addDepVar.restype = None
    _addDepVar.argtypes = [
        C.c_void_p,
        C.c_int,
        C.c_int,
        C.c_int,
        C.c_void_p,
        C.POINTER(C.c_int),
        C.POINTER(C.c_double),
    ]

    _delete = lib.DepVarList__delete
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

    def addDepVar(
        self,
        nElemsOut,
        elemSizeOut,
        elemSizeIn,
        variable,
        indices,
        sens,
    ):
        return self._addDepVar(
            C.addressof(self),
            nElemsOut,
            elemSizeOut,
            elemSizeIn,
            C.addressof(variable),
            indices,
            sens,
        )

    def delete(
        self,
    ):
        return self._delete(
            C.addressof(self),
        )

