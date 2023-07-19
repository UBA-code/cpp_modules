#pragma once
#include "stdlib.h"

template <typename len, typename T, typename Func>
void iter(len length, T arr[], Func (*func)(T &s))
{
	len i = -1;

	if (!arr)
		return ;
	while (++i < length)
		func(arr[i]);
}
