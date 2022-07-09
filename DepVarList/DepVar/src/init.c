#include <stdlib.h>
#include "../DepVar.h"

void DepVar__init(DepVar *self)
{
    self->prev        = NULL;
    self->next        = NULL;
    self->variable    = NULL;
    self->sens        = NULL;
    self->indices     = NULL;
    self->elemSizeIn  = 0;
    self->elemSizeOut = 0;
    self->sensFlag    = 0;
}
