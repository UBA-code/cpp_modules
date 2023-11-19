#include "Span.hpp"

Span::Span() : size(0) {}

Span::Span(unsigned int n) : size(n) {}

Span::Span(const Span &obj)
{
	*this = obj;
}

Span &Span::operator=(const Span &obj)
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
	if (this->arr.size() >= this->size)
		throw(filledContainer());
	this->arr.push_back(n);
}

int Span::shortestSpan()
{
	if (this->arr.size() <= 1)
		throw(emptyContainer());

	std::vector<int> tmp(this->arr);
	int shortest;

	std::sort(tmp.begin(), tmp.end());

	shortest = tmp[1] - tmp[0];
	for (size_t i = 0; i < tmp.size(); i++)
		if (i + 1 < tmp.size() && tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	return (shortest);
}

int Span::longestSpan()
{
	if (this->arr.size() <= 1)
		throw(emptyContainer());
	int min;
	int max;

	max = *(std::max_element(this->arr.begin(), this->arr.end()));
	min = *(std::min_element(this->arr.begin(), this->arr.end()));
	return (max - min);
}

void Span::print()
{
	std::vector<int>::iterator itt = (this->arr).begin();

	for (; itt != this->arr.end(); itt++)
	{
		std::cout << *itt << "\n";
	}
}
