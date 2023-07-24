#pragma once
#include "iostream"
#include "algorithm"
#include <iterator>

class notFound : public std::exception {
	public:
		const char* what() const throw()
		{
			return ("no occurrence is found\n");
		};
};

template <typename T> bool easyfind(T &argOne, int n)
{
	if (std::find(argOne.begin(), argOne.end(), n) == argOne.end())
		throw (notFound());
	std::cout << n << " Found\n";
	return (1);
}
