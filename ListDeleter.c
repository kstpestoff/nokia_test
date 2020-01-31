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
	struct List* next;
	void* payload;
}


#define WORDS_MAX_LENGTH (45)	// maximum primes number 
/*************************************************************************************************//**
@brief 
****************************************************************************************************/
void AsciiTextWordCalculation
(
	const char* restrict pText,		///< [out] output sum
	const INT textLen,				///< [in] text length in bytes
	const char* restrict pWordsQtty	///< [out] output array. Must be 45 bytes length 
)
{
	assert(pText);
	assert(pWordsQtty);

	assert (textLen > 0);

	memset( pWordsQtty, 0x0, WORDS_MAX_LENGTH*sizeof(char) );

// iterate data there
// we assume that we have data as ascii, because we use C-language
// and we don't have any C++ features as templates, STL-library and
// OOP features. We have 90 - minutes restriction for coding that's 
// I choose this algorithm. 
	int wordLen = 0;

	for (int i = 0; i < textLen; i++)
	{

		if ((pText[] != '/n' ) || (pText[] != 0x0 ))
		{
			wordLen++;			
		}
		else
		{
			assert(wordLen < WORDS_MAX_LENGTH);
			pWordsQtty[wordLen]++;

			wordLen = 0;
		}
	}

	if (wordLen != 0)
	{
		pWordsQtty[wordLen]++;				
	}
}