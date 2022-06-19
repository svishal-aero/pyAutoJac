#include <stdlib.h>
#include "../DepVarList.h"

void DepVarList__delete(DepVarList *self)
{
    while(self->first!=NULL)
    {
        DepVar *temp = self->first;
        self->first = temp->next;
        DepVar__delete(temp);
        free(temp);
    }
    DepVarList__init(self);
}
