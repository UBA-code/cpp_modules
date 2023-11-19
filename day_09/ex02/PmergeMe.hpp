#pragma once
#include "iostream"
#include "vector"
#include "deque"
#include <ctime>
#include "cstdlib"
#include <iomanip> 

#define VECTOR 0
#define DEQUE 1

template <typename T>
void    insertionSort(T &arr);
template <typename T>
void    merge(T &left, T &right, T &arr);
template <typename T>
void    mergeSort(T &arr);
void	pMergeMe(char **av, int container);
void	parse(char **av);
