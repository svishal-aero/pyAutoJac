#include <stdlib.h>
#include "../Variable.h"

void Variable__delete(Variable *self)
{
    if(self->data != NULL) free(self->data);
    DepVarList__delete(&(self->depVarList));
    Variable__init(self);
}
