#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Jacobian/Jacobian.h"

static void printVar(Variable *var, char *varName)
{
    printf("%s =\n", varName);
    for(int i=0; i<var->nElems; i++)
    {
        printf("   ");
        for(int j=0; j<var->elemSize; j++)
            printf(" %le", var->data[i*var->elemSize+j]);
        printf("\n");
    }
}

int main()
{
    Variable *x = calloc(1, sizeof(Variable));
    Variable__init(x);
    Variable__create(x, 2, 3);
    for(int i=0; i<6; i++) x->data[i] = i+1;
    printVar(x, "x");

    Variable *y = calloc(1, sizeof(Variable));
    Variable__init(y);
    Variable__create(y, 2, 1);
    y->data[0] = pow(x->data[0],2) + pow(x->data[1],2) + pow(x->data[2],2);
    y->data[1] = pow(x->data[3],2) + pow(x->data[4],2) + pow(x->data[5],2);
    printVar(y, "y");

    Variable *z = calloc(1, sizeof(Variable));
    Variable__init(z);
    Variable__create(z, 2, 1);
    z->data[0] = log(y->data[0]);
    z->data[1] = log(y->data[1]);
    printVar(z, "z");

    Variable__addDepVar(y, x, NULL, NULL);
    DepVar *dep_x = y->depVarList.first;
    for(int i=0; i<2; i++) for(int j=0; j<1; j++) for(int jD=0; jD<3; jD++)
        dep_x->sens[j][jD][i] = 2*(i*3+jD)+2;

    printf("dy/dx =\n");
    for(int i=0; i<2; i++) for(int j=0; j<1; j++) for(int jD=0; jD<3; jD++)
        printf("    %le\n", dep_x->sens[j][jD][i]);

    Variable__addDepVar(z, y, NULL, NULL);
    DepVar *dep_y = z->depVarList.first;
    dep_y->sens[0][0][0] = 1.0/14;
    dep_y->sens[0][0][1] = 1.0/77;
    printf("dz/dy =\n");
    for(int i=0; i<2; i++) printf("    %le\n", dep_y->sens[0][0][i]);

    Jacobian *J = calloc(1, sizeof(Jacobian));
    Jacobian__init(J);
    Jacobian__create(J, z, x);
    Jacobian__evaluate(J);

    printf("nRows = %d\n", J->nRows);

    printf("offsets = ");
    for(int iRow=0; iRow<J->nRows+1; iRow++)
        printf(" %d", J->offsets[iRow]);
    printf("\n");

    printf("(Row, Column, Derivative) = \n");
    for(int iRow=0; iRow<J->nRows; iRow++)
        for(int i=J->offsets[iRow]; i<J->offsets[iRow+1]; i++)
            printf("%d %d %le\n", iRow, J->columns[i], J->entries[i]);

    Jacobian__delete(J); free(J);
    Variable__delete(z); free(z);
    Variable__delete(y); free(y);
    Variable__delete(x); free(x);
}
