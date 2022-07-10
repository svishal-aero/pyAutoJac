#pragma once

#include "../DepVarList/DepVarList.h"

#pragma pack(1)
typedef struct Variable
{
    int size;
    int nElems;
    int elemSize;
    double *data;
    DepVarList depVarList;
}
Variable;
#pragma pack()

void Variable__init(Variable *self);

void Variable__delete(Variable *self);

void Variable__create(Variable *self,
                      int nElems,
                      int elemSize);

void Variable__addDepVar(Variable *self,
                         Variable *variable,
                         int *indices,
                         double ***sens);
