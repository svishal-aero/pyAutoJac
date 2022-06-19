#include <stdlib.h>
#include <assert.h>
#include "HashMap.h"
#include "../Jacobian.h"

static int nCols;
static HashMap jacRowMap;

static int compare(const void *a, const void *b) { return ( *(int*)a - *(int*)b ); }

static void evalNumEntries(Jacobian *jacobian, Variable *var, int iVar, int jVar)
{
    for(DepVar *dep=var->depVarList.first; dep!=NULL; dep=dep->next)
    {
        Variable *dVar = dep->variable;

        if(dVar==jacobian->input)
        {
            int iDVar = (dep->indices==NULL) ? iVar : dep->indices[iVar];
            for(int jDVar=0; jDVar<dVar->elemSize; jDVar++)
            {
                int index = iDVar*dVar->elemSize + jDVar;
                nCols += HashMap__addKey(&jacRowMap, index);
            }
        }

        else
        {
            int iDVar = (dep->indices==NULL) ? iVar : dep->indices[iVar];
            for(int jDVar=0; jDVar<dVar->elemSize; jDVar++)
            {
                evalNumEntries(jacobian, dVar, iDVar, jDVar);
            }
        }
    }
}

void Jacobian__create(Jacobian *self, Variable *output, Variable *input)
{
    self->input  = input;
    self->output = output;
    self->nRows  = output->size;
    self->offsets = calloc(self->nRows+1, sizeof(int));
    self->offsets[0] = 0;

    for(int iOutput=0; iOutput<output->nElems; iOutput++)
    {
        for(int jOutput=0; jOutput<output->elemSize; jOutput++)
        {
            int index = iOutput*output->elemSize+jOutput;
            HashMap__init(&jacRowMap); nCols = 0;
            evalNumEntries(self, output, iOutput, jOutput);
            self->offsets[index+1] = self->offsets[index] + nCols;
            HashMap__delete(&jacRowMap);
        }
    }

    self->columns = calloc(self->offsets[self->nRows]*output->elemSize
                          *input->elemSize, sizeof(int));

    self->entries = calloc(self->offsets[self->nRows]*output->elemSize
                          *input->elemSize, sizeof(double));

    for(int iOutput=0; iOutput<output->nElems; iOutput++)
    {
        for(int jOutput=0; jOutput<output->elemSize; jOutput++)
        {
            int index = iOutput*output->elemSize+jOutput;
            HashMap__init(&jacRowMap); nCols = 0;
            evalNumEntries(self, output, iOutput, jOutput);
            HashMap__setColumns(&jacRowMap, self->columns + self->offsets[index]);
            qsort(self->columns + self->offsets[index],
                  self->offsets[index+1]-self->offsets[index],
                  sizeof(int), compare);
            HashMap__delete(&jacRowMap);
        }
    }
}
