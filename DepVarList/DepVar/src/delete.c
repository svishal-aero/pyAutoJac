#include <stdlib.h>
#include "../DepVar.h"

void DepVar__delete(DepVar *self)
{
    DepVar *prev = self->prev;
    DepVar *next = self->next;
    if(prev!=NULL) prev->next = next;
    if(next!=NULL) next->prev = prev;
    if(self->sensFlag)
    {
        for(int i=0; i<self->elemSizeOut; i++)
        {
            for(int j=0; j<self->elemSizeIn; j++)
            {
                free(self->sens[i][j]);
            }
            free(self->sens[i]);
        }
        free(self->sens);
    }
    DepVar__init(self);
}
