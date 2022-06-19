#include <stdlib.h>
#include "../DepVarList.h"

void DepVarList__addDepVar(DepVarList *self, int nElemsOut, int elemSizeOut,
                           int elemSizeIn, void *variable, int *indices,
                           double *sens)
{
    DepVar *temp = calloc(1, sizeof(DepVar));
    DepVar__init(temp);
    DepVar__create(temp, nElemsOut, elemSizeOut,
                   elemSizeIn, variable, indices, sens);

    if(self->first==NULL && self->last==NULL)
    {
        self->first = temp;
        self->last  = temp;
    }
    else 
    {
        temp->prev = self->last;
        self->last->next = temp;
        self->last = temp;
    }
}
