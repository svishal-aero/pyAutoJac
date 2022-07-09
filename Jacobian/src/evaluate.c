#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../Jacobian.h"

static int compare(const void *a, const void *b) { return ( *(int*)a - *(int*)b ); }

static void evalEntries(Jacobian *jacobian, int iRow, Variable *var, int iVar, int jVar, double sens)
{
    for(DepVar *dep=var->depVarList.first; dep!=NULL; dep=dep->next)
    {
        Variable *dVar = dep->variable;

        if(dVar==jacobian->input)
        {
            int iDVar = (dep->indices==NULL) ? iVar : dep->indices[iVar];
            if(iDVar>=0) for(int jDVar=0; jDVar<dVar->elemSize; jDVar++)
            {
                int index = iDVar*dVar->elemSize + jDVar;
                int iEntry = (void*)bsearch(&index,
                                   jacobian->columns+jacobian->offsets[iRow],
                                   jacobian->offsets[iRow+1]-jacobian->offsets[iRow],
                                   sizeof(int), compare)
                           - (void*)(jacobian->columns);
                iEntry /= sizeof(int);
                printf("iEntry = %d\n", iEntry);
                jacobian->entries[iEntry] += sens*dep->sens[jVar][jDVar][iVar];
            }
        }

        else
        {
            int iDVar = (dep->indices==NULL) ? iVar : dep->indices[iVar];
            if(iDVar>=0) for(int jDVar=0; jDVar<dVar->elemSize; jDVar++)
            {
                evalEntries(jacobian, iRow, dVar, iDVar, jDVar, sens*dep->sens[jVar][jDVar][iVar]);
            }
        }
    }
}

void Jacobian__evaluate(Jacobian *self)
{
    for(int iRow=0; iRow<self->nRows; iRow++)
        for(int i=self->offsets[iRow]; i<self->offsets[iRow+1]; i++)
            self->entries[i] = 0.0;

    for(int iOutput=0; iOutput<self->output->nElems; iOutput++)
    {
        for(int jOutput=0; jOutput<self->output->elemSize; jOutput++)
        {
            int index = iOutput*self->output->elemSize+jOutput;
            evalEntries(self, index, self->output, iOutput, jOutput, 1.0);
        }
    }
}
