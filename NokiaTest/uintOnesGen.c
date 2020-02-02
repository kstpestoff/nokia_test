/*************************************************************************************************//**
@file   uintOnesGen.c
@author Pestoff K.A.
@brief	4. Write a function that takes a 32-bit unsigned integer number and returns the maximum 
			and minimum 32-bit unsigned integer numbers which can be obtained using the same 
			number of bits set to 1 as in the taken number. 

		we use c99.
*****************************************************************************************************/
#include "uintOnesGen.h"
#include "limits.h"

// from Henry Warren book.
static inline int onesQtty(UINT x)
{
	x = x - ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x + (x >> 4)) & 0x0F0F0F0F;
	x = x + (x >> 8);
	x = x + (x >> 16);
	return x & 0x0000003F;
}

void uintOnesGen
(
	UINT val,		///> [in] input unsigned 32 value 
	UINT* pMin,		///> [out] minimal value that can be
	UINT* pMax		///> [out] maximal value that can be
) 
{
	INT onesInVal = onesQtty(val);

	if (onesInVal == 32)
	{
		(*pMin) = (*pMax) = UINT_MAX;
	}
	else
	{
		(*pMin) = (1 << (onesInVal )) - 1;
		(*pMax) = ((1 << (onesInVal )) - 1) << (32 - onesInVal);
	}
}