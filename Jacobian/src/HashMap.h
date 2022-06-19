#pragma once

#define HASH_MAP_SIZE 9973

#include <stdlib.h>

#pragma pack(1)
typedef struct CollisionItem
{
    struct CollisionItem *next;
    int key;
}
CollisionItem;

typedef struct HashMap
{
    int nItems;
    CollisionItem itemLists[HASH_MAP_SIZE];
}
HashMap;
#pragma pack()

inline void CollisionItem__init(CollisionItem *self)
{ self->next = NULL; self->key = -1; }

inline void CollisionItem__delete(CollisionItem *self)
{
    CollisionItem *tmp = self->next, *tmp2;
    while(tmp!=NULL) { tmp2=tmp; tmp=tmp->next; free(tmp2); }
}

inline int CollisionItem__addKey(CollisionItem *self, int key)
{
    CollisionItem *tmp = self; while(tmp->next!=NULL)
    { if(tmp->next->key==key) return 0; tmp=tmp->next; }
    tmp->next = (CollisionItem*)calloc(1, sizeof(CollisionItem));
    CollisionItem__init(tmp->next); tmp->next->key=key; return 1;
}

inline int* CollisionItem__setColumns(CollisionItem *self, int *cols)
{
    CollisionItem *tmp = self->next;
    while(tmp!=NULL) { *(cols++) = tmp->key; tmp=tmp->next; }
    return cols;
}

inline void HashMap__init(HashMap *self)
{ for(int i=0; i<HASH_MAP_SIZE; i++) CollisionItem__init(self->itemLists+i); }

inline void HashMap__delete(HashMap *self)
{ for(int i=0; i<HASH_MAP_SIZE; i++) CollisionItem__delete(self->itemLists+i); }

inline int HashMap__addKey(HashMap *self, int key)
{ return CollisionItem__addKey(self->itemLists + key%HASH_MAP_SIZE, key); }

inline void HashMap__setColumns(HashMap *self, int *cols)
{ for(int i=0; i<HASH_MAP_SIZE; i++) cols = CollisionItem__setColumns(self->itemLists+i, cols); }

#undef HASH_MAP_SIZE
