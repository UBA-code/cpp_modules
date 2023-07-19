#pragma once

template <typename len, typename T, typename Func, typename ch>
void iter(len length, T arr, Func (func)(ch c))
{
	len i = 0;

	while (i < length)
	{
		func(arr[i]);
		i++;
	}
}
