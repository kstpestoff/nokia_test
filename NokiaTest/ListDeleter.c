/*************************************************************************************************//**
@file   wordscounter.c
@author Pestoff K.A.
@brief  There is a list:
		struct List {
			struct List* next;
			SomeDataType payload;
		}
		Write a function that removes every fifth (5) element from this list.

		we use c99.
*****************************************************************************************************/
/*************************************************************************************************//**
For simplicity: 
1. Firstly we redefine list as


we use c99.
****************************************************************************************************/
#include "assert.h" 

typedef struct tList
{
	List* next;
	void* payload;
};

void deleteList();