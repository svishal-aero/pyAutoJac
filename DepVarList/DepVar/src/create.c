#include <stdio.h>
#include <stdlib.h>
#include "../DepVar.h"

void DepVar__create(DepVar *self, int nElemsOut, int elemSizeOut,
                    int elemSizeIn, void *variable, int *indices,
                    double *sens)
{
    int size = nElemsOut*elemSizeOut*elemSizeIn;
    
    if(indices!=NULL) self->indices = indices;

    if(sens!=NULL) self->sens = sens;

    if(sens==NULL) self->sensFlag = 1;
    if(sens==NULL) self->sens = calloc(size, sizeof(double));

    self->variable = variable;
}
