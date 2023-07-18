#pragma once


template <typename T> void swap(T& argOne, T& argTwo)
{
	T temp;

	temp = argOne;
	argOne = argTwo;
	argTwo = temp;
}

template <typename T> T min(T& argOne, T& argTwo)
{
	return (argOne < argTwo ? argOne : argTwo);
}

template <typename T> T max(T& argOne, T& argTwo)
{
	return (argOne > argTwo ? argOne : argTwo);
}
