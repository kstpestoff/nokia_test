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
3. We suppose that all data in payload is dynamically allocated

we use c99.
****************************************************************************************************/
#include "listDeleter.h" 

#include <stdlib.h> 
#include <assert.h> 

/*************************************************************************************************//**
@brief getNextListELement get next element
****************************************************************************************************/
sList* getNextListELement(sList* pThis)
{
	return pThis->pNext;
}

/*************************************************************************************************//**
@brief deleteListELement delete next element in the list
****************************************************************************************************/
void deleteListELement(sList* pThis)
{
	assert(pThis);

// check if it last element 
	sList* pCur = pThis->pNext;
	sList* pNext = pCur->pNext;

	if (pCur)
	{
		assert(pCur->pPayload);

		if (pCur->pPayload)
		{
			free(pCur->pPayload);
		}

		pThis->pNext = pNext;
	}
}

/*************************************************************************************************//**
@brief generateList generate test list 
****************************************************************************************************/
sList* generateList()
{
// here we generate array and add this array in list
// const INT elementsQtty = 23;
#define elementsQtty 23

	INT **pData;
// read about suppose #3 in the top of the file
	pData = (INT**)malloc(sizeof(INT*) * elementsQtty);
	assert(pData);

	for (INT i = 0; i < elementsQtty; i++)
	{
		pData[i] = (INT*)malloc(sizeof(INT));
		assert(pData[i]);
	}

	sList*  pThis = (sList*)createEmptyList();

	for (INT i = 0; i < elementsQtty; i++)
	{
		pData[i][0] = i;
		pushList(pData[i], pThis);
	}

	return pThis;
}

void printList(sList* pThis)
{
	INT idx = 0;
	sList* pCurList = pThis->pNext;
	assert(pThis);

	printf("firt element: is start element\n");
	if (!pThis->pNext)
	{
		printf("oops that's epty List");
	}

	while (pCurList)
	{
		idx++;
		INT* pData = (INT*)pCurList->pPayload;
		printf("data in list idx: %d is { %d }\n", idx, pData[0]);
		pCurList = pCurList->pNext;
	}
}

/*************************************************************************************************//**
@brief  findEndList find the last element in list.
****************************************************************************************************/
sList* findEndList(sList* pThis)
{
	assert(pThis);
	sList* pResList = pThis;
	
	while (pResList->pNext)
	{
		pResList = pResList->pNext;
	}

	return pResList;
}

/*************************************************************************************************//**
@brief  pushList push data.
****************************************************************************************************/
void pushList(void* pData, sList* pThis)
{
	assert(pThis);
	assert(pData);

	sList* pLast = findEndList(pThis);
	sList* pNew = (sList*)malloc(sizeof(sList));

	assert(pNew);

	pNew->pNext = (void*)NULL;
	pLast->pNext = pNew;

	pNew->pPayload = pData;
}

/*************************************************************************************************//**
@brief  createEmptyList crete empty list with first start element.
****************************************************************************************************/
sList* createEmptyList()
{
	sList* pList = (sList*)malloc(sizeof(sList));

	memset(pList, 0x0, sizeof(sList));

	pList->pPayload = (void*)LIST_FIRST_ELEMENT;

	return pList;
}

/*************************************************************************************************//**
@brief  getResList delete every fifth element in the list
****************************************************************************************************/
void getResList(sList* pThis)
{
	assert(pThis);
	INT idx = 0;
// delete every fifth element
	while (pThis->pNext)
	{
		sList* pPrev = pThis;
		pThis = (sList*)pThis->pNext;
		idx++;
		if (idx >= 5)
		{
			idx = 0;
			deleteListELement(pPrev);
		}
	}
}
