#include <stdio.h>   
#include <stdlib.h> 

#include "primeNumbers.h"
#include "wordscounter.h"

void main()
{	
	const INT primesQtty = 10;
	INT sum = 0;

	USHORT* pPrimes = (USHORT*)malloc(primesQtty*sizeof(USHORT));

	primeNumberSum
	(
		&sum,			///< [out] output sum
		primesQtty,		///< [in] primes number quantity
		pPrimes 		///< [in] pointer to output primes array 
	);

	printf("primeNumberSum: ");
	printf("sum for %d first primes numbers is %d\n", primesQtty, sum);

	for (int i = 0; i < primesQtty; i++)
	{
		printf("cur primes [%d] is %d\n", i, pPrimes[i]);
	}

	char* pWordsQtty = (char*)malloc(WORDS_MAX_LENGTH * sizeof(char));
			
	AsciiTextWordCalculation
	(
		"I don't need no education",	///< [out] output sum
		26,								///< [in] text length in bytes
		pWordsQtty						///< [out] output array. Must be 45 bytes length 
	);

	printf("AsciiTextWordCalculation: ");

	for (int i = 0; i < primesQtty; i++)
	{
		printf("cur primes [%d] is %d\n", i, pPrimes[i]);
	}


	return;
}