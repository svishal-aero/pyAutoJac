#pragma once

#pragma pack(1)
typedef struct DepVar
{
    void     *prev;
    void     *next;
    void     *variable;
    int      *indices;
    double ***sens;
    int       elemSizeIn;
    int       elemSizeOut;
    int       sensFlag;
}
DepVar;
#pragma pack()

void DepVar__init(DepVar *self);
void DepVar__delete(DepVar *self);
void DepVar__create(DepVar *self, int nElemsOut, int elemSizeOut,
                    int elemSizeIn, void *variable, int *indices,
                    double ***sens);
