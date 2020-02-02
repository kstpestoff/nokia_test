#include <stdio.h>   
#include <stdlib.h> 

#include "primeNumbers.h"
#include "wordsCounter.h"
#include "listDeleter.h"
#include "uintOnesGen.h"
#include "treeTraceCalc.h"

//#define TEST_1
//#define TEST_2
//#define TEST_3

#define TEST_4
#define TEST_5

void main()
{	
#ifdef TEST_1
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
#endif

#ifdef TEST_2
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
#endif

#ifdef TEST_3

	printf("3. List deleter: ");
	sList* pList = generateList();
	printList(pList);
	
	getResList(pList);
	printf("after detelting every fifth element\n");
	printList(pList);
#endif
#ifdef TEST_4

	printf("4. uintOnesGen: ");

	UINT max;
	UINT min;
	UINT val = 7<<2;

	uintOnesGen(val, &min, &max);

	printf("uintOnesGen: [val,min,max]: [%u,0x%X,0x%X]", val, min, max);
#endif
#ifdef TEST_5

	printf("5. treeTraceCalc: ");


	sBinTree *pTree;



	for (INT i = 0; i < 20; i++)
	{ 
		binIsertionTree(sBinTree * pTree, int item)
	}

#endif
	return;
}


