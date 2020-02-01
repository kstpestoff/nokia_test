#include <stdio.h>   
#include <stdlib.h> 

#include "primeNumbers.h"
#include "wordsCounter.h"
#include "listDeleter.h"

void main()
{	
	const INT primesQtty = 10;
	INT sum = 0;

	USHORT* pPrimes = (USHORT*)malloc(primesQtty*sizeof(USHORT));

	printf("1. primeNumberSum: ");
	primeNumberSum
	(
		&sum,			///< [out] output sum
		primesQtty,		///< [in] primes number quantity
		pPrimes 		///< [in] pointer to output primes array 
	);

	printf("sum for %d first primes numbers is %d\n", primesQtty, sum);

	for (int i = 0; i < primesQtty; i++)
	{
		printf("cur primes [%d] is %d\n", i, pPrimes[i]);
	}

	char* pWordsQtty = (char*)malloc(WORDS_MAX_LENGTH * sizeof(char));
			
	printf("2. AsciiTextWordCalculation: ");
	AsciiTextWordCalculation
	(  /*1 5     4    2  9        */
		"I don't need no education",	///< [out] output sum
		26,								///< [in] text length in bytes
		pWordsQtty						///< [out] output array. Must be 45 bytes length 
	);

	for (int i = 0; i < WORDS_MAX_LENGTH; i++)
	{
		printf("words len %d is %d words\n", i, pWordsQtty[i]);
	}



	return;
}