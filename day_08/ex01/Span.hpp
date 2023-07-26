#pragma once
#include "iostream"
#include "vector"
#include "algorithm"
#include "iterator"

class Span {
	private:
		std::vector<int>	arr;
		unsigned int		size;
	public:
		Span();
		Span(unsigned int n);
		Span(Span& obj);
		Span& operator=(Span& obj);
		~Span();
		void	addNumber(int n);
		void	addArray(std::vector<int> &array);
		int		shortestSpan();
		int		longestSpan();
		void	print();
		class emptyContainer : public std::exception {
			public:
				const char * what() const throw () {
					return ("Empty container\n");
				};
		};
		class filledContainer : public std::exception {
			public:
				const char * what() const throw () {
					return ("The container is completely filled\n");
				};
		};
};
