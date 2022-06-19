#include <stdlib.h>
#include "../DepVarList.h"

void DepVarList__init(DepVarList *self)
{
    self->first = NULL;
    self->last  = NULL;
}
