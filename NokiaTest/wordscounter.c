/*************************************************************************************************//**
@file   wordscounter.c
@author Pestoff K.A.
@brief  2. Write a function that counts the number of words in the text for each word length 
		(X words with 1-letter length, Y words with 2-letters length, etc.) 

		we use c99.
*****************************************************************************************************/
/*************************************************************************************************//**
For simplicity: 
1. we assume that in the world most logest word is pneumonoultramicroscopicsilicovolcanoconiosis 
that is 45 letter long. 
2. Also we suppose that we have ASCI code input string.
We can do this because we don't have any additional restriction in statement of the problem.


we use c99.
****************************************************************************************************/
#include <assert.h> 
#include "types.h" 

#define WORDS_MAX_LENGTH (45)	// maximum primes number 
/*************************************************************************************************//**
@brief 
****************************************************************************************************/
void AsciiTextWordCalculation
(
	char* pText,		///< [out] output sum
	INT textLen,				///< [in] text length in bytes
	char* pWordsQtty	///< [out] output array. Must be 45 bytes length 
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

		if ( (pText[i] != 0x20) )
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
	
	assert(wordLen < WORDS_MAX_LENGTH);
	pWordsQtty[--wordLen]++;
}
