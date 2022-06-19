#pragma once

#include "DepVar/DepVar.h"

#pragma pack(1)
typedef struct DepVarList
{
    DepVar *first;
    DepVar *last;
}
DepVarList;
#pragma pack()

void DepVarList__init(DepVarList *self);
void DepVarList__addDepVar(DepVarList *self, int nElemsOut, int elemSizeOut,
                           int elemSizeIn, void *variable, int *indices,
                           double *sens);
void DepVarList__delete(DepVarList *self);
