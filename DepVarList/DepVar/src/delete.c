#include <stdlib.h>
#include "../DepVar.h"

void DepVar__delete(DepVar *self)
{
    DepVar *prev = self->prev;
    DepVar *next = self->next;
    if(prev!=NULL) prev->next = next;
    if(next!=NULL) next->prev = prev;
    if(self->sensFlag) free(self->sens);
    DepVar__init(self);
}
