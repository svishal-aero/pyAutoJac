#pragma once

#include "../Variable/Variable.h"

#pragma pack(1)
typedef struct Jacobian
{
    Variable *input, *output;
    int nRows, *offsets, *columns;
    double *entries;
}
Jacobian;
#pragma pack()

void Jacobian__init(Jacobian *self);
void Jacobian__create(Jacobian *self, Variable *output, Variable *input);
void Jacobian__evaluate(Jacobian *self);
void Jacobian__delete(Jacobian *self);
