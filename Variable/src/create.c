#include <stdlib.h>
#include "../Variable.h"

void Variable__create(Variable *self, int nElems, int elemSize)
{
    self->size = nElems * elemSize;
    self->nElems = nElems;
    self->elemSize = elemSize;
    self->data = calloc(self->size, sizeof(double));
    for(int i=0; i<self->size; i++) self->data[i] = 0;
}
