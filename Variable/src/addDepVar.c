#include "../Variable.h"

void Variable__addDepVar(Variable *self, Variable *var,
                         int *indices, double ***sens)
{
    DepVarList__addDepVar(&(self->depVarList), self->nElems,
                          self->elemSize, var->elemSize, var,
                          indices, sens);
}
