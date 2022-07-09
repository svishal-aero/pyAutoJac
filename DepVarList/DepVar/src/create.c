#include <stdio.h>
#include <stdlib.h>
#include "../DepVar.h"

void DepVar__create(DepVar *self, int nElemsOut, int elemSizeOut,
                    int elemSizeIn, void *variable, int *indices,
                    double ***sens)
{
    self->elemSizeOut = elemSizeOut;
    self->elemSizeIn  = elemSizeIn;
    
    if(indices!=NULL) self->indices = indices;

    if(sens!=NULL) self->sens = sens;

    if(sens==NULL)
    {
        self->sensFlag = 1;
        self->sens = calloc(elemSizeOut, sizeof(double**));
        for(int i=0; i<elemSizeOut; i++)
        {
            self->sens[i] = calloc(elemSizeIn, sizeof(double*));
            for(int j=0; j<elemSizeIn; j++)
            {
                self->sens[i][j] = calloc(nElemsOut, sizeof(double));
            }
        }
    }

    self->variable = variable;
}
