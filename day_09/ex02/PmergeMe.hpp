#pragma once
#include "iostream"
#include "vector"
#include "deque"
#include <sys/time.h>

template <typename T>
void    insertionSort(T &arr);
template <typename T>
void    merge(T &left, T &right, T &arr);
template <typename T>
void    mergeSort(T &arr);
void    pMergeMe(char **av);
