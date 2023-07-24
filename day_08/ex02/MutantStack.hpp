#pragma once
#include "iostream"
#include "stack"
#include "iterator"

template<typename T>
class MutantStack : public std::stack<T>
{
	private:
		std:
	public:
		std::iterator<T> begin();
		std::iterator<T> end();
};
