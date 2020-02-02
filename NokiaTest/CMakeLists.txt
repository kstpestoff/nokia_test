cmake_minimum_required(VERSION 3.2)

project(nokia_test)

add_executable(nokia_test
	main.c	
	primeNumbers.c
	primeNumbers.h
	wordsCounter.c
	wordsCounter.h
	listDeleter.c
	listDeleter.h
	uintOnesGen.c
	uintOnesGen.h
	treeTraceCalc.c
	treeTraceCalc.h
	types.h
)

target_compile_features(nokia_test PRIVATE c_std_99)