#include <stdlib.h>
#include "../Variable.h"

void Variable__init(Variable *self)
{
    self->size = 0;
    self->nElems = 0;
    self->elemSize = 0;
    self->data = NULL;
    self->calcFlag = 0;
    self->calculate = NULL;
    DepVarList__init(&(self->depVarList));
}
