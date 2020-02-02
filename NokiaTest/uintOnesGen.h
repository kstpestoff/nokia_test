/*************************************************************************************************//**
@file   uintOnesGen.h
@author Pestoff K.A.
@brief

		we use c99.
*****************************************************************************************************/
#include "types.h"


void uintOnesGen
(
	UINT val,		///> [in] input unsigned 32 value 
	UINT* pMin,		///> [out] minimal value that can be
	UINT* pMax		///> [out] maximal value that can be
);