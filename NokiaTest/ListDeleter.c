/*************************************************************************************************//**
@file   listDeleter.c
@author Pestoff K.A.
@brief  There is a list:
		struct List 
		{
			struct List* next;
			SomeDataType payload;
		}
		Write a function that removes every fifth (5) element from this list.

		we use c99.
*****************************************************************************************************/
/*************************************************************************************************//**
For simplicity: 
1. We assume that the last element is 0xFFFFFFFF
2. We suppose that data in List allocated and we must free it.
we use c99.
****************************************************************************************************/
#include "listDeleter.h" 

#include <stdlib.h> 
#include <assert.h> 

sList* getNextListELement(sList* pThis)
{
	return pThis->pNext;
}

void deleteListELement(sList* pThis) 
{
	assert(pThis);

	sList* pNext = pThis->pNext;
	
	assert(pThis->pPayload);

	if (pThis->pPayload)
	{
		free(pThis->pPayload);
	}

	pThis = pNext;
}
void generateList(sList* pThis)
{
	
}

void getResList(sList* pThis)
{
	assert(pThis);
	INT idx = 1;
// delete every fifth element
	while (pThis->pNext)
	{
		idx++;
		pThis = (sList*)pThis->pNext;
		if (idx >= 5)
		{
			idx = 1;
			deleteListELement(pThis);
		}
	}
}
