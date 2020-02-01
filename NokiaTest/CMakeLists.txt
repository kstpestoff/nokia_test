cmake_minimum_required(VERSION 3.2)

project(nokia_test)

add_executable(main 
	main.c	
	primeNumbers.c
	primeNumbers.h
	wordsCounter.c
	wordsCounter.h
	listDeleter.c
	listDeleter.h
)

set (CMAKE_C_STANDARD 99)