#include <stdlib.h>
#include "../Variable.h"

void Variable__calculate(Variable *self)
{
    for(DepVar *depVar=self->depVarList.first; depVar!=NULL; depVar++)
    {
        Variable *var = depVar->variable;
        if(!var->calcFlag) Variable__calculate(var);
    }
    self->calculate(self);
    self->calcFlag = 1;
}
