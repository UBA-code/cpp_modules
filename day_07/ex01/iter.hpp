#pragma once
#include "stdlib.h"

template <typename T, typename K>
void iter(T *arr, size_t length, void (*func)(K &s))
{
	size_t i = -1;

	if (!arr)
		return ;
	for (i = 0; i < length; i++)
		func(arr[i]);
}
