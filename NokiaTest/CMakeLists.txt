cmake_minimum_required(VERSION 3.2) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.
set(CMAKE_C_FLAGS "std=c99")

add_executable(main 
  main.c
  primeNumbers.c
  primeNumbers.h
)
