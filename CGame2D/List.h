#pragma once
#include <stdlib.h>
#include <stdbool.h>

#define cgList(type) type*

cgList(void) cgListCreate(unsigned int elementSize);

unsigned int cgListLength(cgList(void) list);

unsigned int cgListElementSize(cgList(void) list);

unsigned int cgListCapacity(cgList(void) list);

cgList(void) cgListInsert(cgList(void) list, void * value, int index);

cgList(void) cgListRemove(cgList(void) list, int index);

cgList(void) cgListPush(cgList(void) list, void * value);

cgList(void) cgListPop(cgList(void) list);

cgList(void) cgListRemoveAll(cgList(void) list, void * value);

cgList(void) cgListRemoveFirst(cgList(void) list, void * value);

cgList(void) cgListRemoveLast(cgList(void) list, void * value);

bool cgListContains(cgList(void) list, void * value);

cgList(void) cgListClear(cgList(void) list);

void cgListDestroy(cgList(void) list);
