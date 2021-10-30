#include <string.h>
#include <math.h>
#include "List.h"

static const unsigned int MetaSize = 2 * sizeof(unsigned int);

cgList(void) cgListCreate(unsigned int elementSize)
{
	unsigned int * list = malloc(MetaSize + 2 * elementSize);
	list[0] = elementSize;
	list[1] = 0;
	return (uint8_t *)list + MetaSize;
}

struct cgListData
{
	unsigned int ElementSize;
	unsigned int * Count;
	unsigned int Capacity;
};

static struct cgListData cgListData(cgList(void) list)
{
	struct cgListData data = { 0 };
	data.ElementSize = *(unsigned int *)((uint8_t *)list - MetaSize);
	data.Count = (unsigned int *)((uint8_t *)list - MetaSize / 2);
	data.Capacity = pow(2.0, floor(log2(*data.Count)) + 1.0);
	return data;
}

unsigned int cgListLength(cgList(void) list)
{
	return *(unsigned int *)((uint8_t *)list - MetaSize / 2);
}

unsigned int cgListElementSize(cgList(void) list)
{
	return *(unsigned int *)((uint8_t *)list - MetaSize);
}

unsigned int cgListCapacity(cgList(void) list)
{
	return cgListData(list).Capacity;
}

cgList(void) cgListInsert(cgList(void) list, void * element, int index)
{
	struct cgListData data = cgListData(list);
	if (index < 0 || index > *data.Count)
	{
		//printf("Trying to add a value to a list, but the index is out of bounds.\n");
		exit(1);
	}
	
	(*data.Count)++;
	if (*data.Count == data.Capacity)
	{
		list = (uint8_t *)realloc((uint8_t *)list - MetaSize, MetaSize + 2 * data.Capacity * data.ElementSize) + MetaSize;
	}
	data = cgListData(list);
	memmove((uint8_t *)list + (index + 1) * data.ElementSize, (uint8_t *)list + index * data.ElementSize, (*data.Count - 1 - index) * data.ElementSize);
	memcpy((uint8_t *)list + index * data.ElementSize, element, data.ElementSize);
	return list;
}

cgList(void) cgListRemove(cgList(void) list, int index)
{
	struct cgListData data = cgListData(list);
	if (index < 0 || index > *data.Count)
	{
		//printf("Trying to remove a value from a list, but the index is out of bounds.\n");
		exit(1);
	}

	for (int j = (index + 1) * (int)data.ElementSize; j < (*data.Count) * (int)data.ElementSize; j++)
	{
		((uint8_t *)list)[j - data.ElementSize] = ((uint8_t *)list)[j];
	}
	(*data.Count)--;
	if (*data.Count == data.Capacity / 2 - 1)
	{
		list = (uint8_t *)realloc((uint8_t *)list - MetaSize, MetaSize + (data.Capacity / 2) * data.ElementSize) + MetaSize;
	}
	return list;
}

cgList(void) cgListPush(cgList(void) list, void * value)
{
	return cgListInsert(list, value, cgListLength(list));
}

cgList(void) cgListPop(cgList(void) list)
{
	if (cgListLength(list) == 0)
	{
		//printf("Trying to pop from an empty list.\n");
		exit(1);
	}
	return cgListRemove(list, cgListLength(list) - 1);
}

cgList(void) cgListRemoveAll(cgList(void) list, void * value)
{
	for (int i = 0; i < cgListLength(list); i++)
	{
		if (memcmp((uint8_t *)list + i * cgListElementSize(list), value, cgListElementSize(list)) == 0)
		{
			list = cgListRemove(list, i);
			i--;
		}
	}
	return list;
}

_Bool cgListContains(cgList(void) list, void * value)
{
	for (int i = 0; i < cgListLength(list); i++)
	{
		if (memcmp((uint8_t *)list + i * cgListElementSize(list), value, cgListElementSize(list))) { return true; }
	}
	return false;
}

cgList(void) cgListClear(cgList(void) list)
{
	cgList(void) newcgList = cgListCreate(cgListElementSize(list));
	cgListDestroy(list);
	return newcgList;
}

void cgListDestroy(cgList(void) list)
{
	free((uint8_t *)list - MetaSize);
}
