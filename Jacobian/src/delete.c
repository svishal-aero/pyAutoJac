#include <stdlib.h>
#include "../Jacobian.h"

void Jacobian__delete(Jacobian *self)
{
    if(self->offsets != NULL) free(self->offsets);
    if(self->columns != NULL) free(self->columns);
    if(self->entries != NULL) free(self->entries);
}
