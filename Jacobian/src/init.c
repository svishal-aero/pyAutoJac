#include <stdlib.h>
#include "../Jacobian.h"

void Jacobian__init(Jacobian *self)
{
    self->input     = NULL;
    self->output    = NULL;
    self->nRows     =    0;
    self->offsets   = NULL;
    self->columns   = NULL;
    self->entries   = NULL;
}
