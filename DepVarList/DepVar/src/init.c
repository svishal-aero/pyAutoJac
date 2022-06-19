#include <stdlib.h>
#include "../DepVar.h"

void DepVar__init(DepVar *self)
{
    self->prev     = NULL;
    self->next     = NULL;
    self->variable = NULL;
    self->sens     = NULL;
    self->indices  = NULL;
    self->sensFlag = 0;
}
