#include "Span.hpp"

Span::Span() : arr(0){}

Span::Span(unsigned int n) : size(n){}

Span::Span(Span& obj)
{
	*this = obj;
}

Span& Span::operator=(Span& obj)
{
	if (this != &obj)
	{
		this->arr = obj.arr;
		this->size = obj.size;
	}
	return (*this);
}

Span::~Span(){};

void Span::addNumber(int n)
{
	if (this->arr.size() < this->size)
		this->arr.push_back(n);
	else
		throw (filledContainer());
}

int	Span::shortestSpan()
{
	if (this->arr.size() <= 1)
		throw (emptyContainer());

	std::vector<int>			tmp(this->arr);
	int							shortest;

	// ? // sort with stable sort
	std::stable_sort(tmp.begin(), tmp.end());

	shortest = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size(); i++)
		if (i + 1 < tmp.size() && tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	return (shortest);
}

int	Span::longestSpan()
{
	if (this->arr.size() <= 1)
		throw (emptyContainer());
	int	min;
	int max;

	max = *(std::max_element(this->arr.begin(), this->arr.end()));
	min = *(std::min_element(this->arr.begin(), this->arr.end()));
	return (max - min);
}

void Span::addArray(std::vector<int> &array)
{
	this->arr.clear();
	std::vector<int>::iterator itt = array.begin();
	for (; itt < array.end(); itt++)
		(this->arr).push_back(*itt);
}
void Span::print()
{
	std::vector<int>::iterator	itt = (this->arr).begin();

	for (; itt < this->arr.end(); itt++)
	{
		std::cout << *itt << "\n";
	}
}
