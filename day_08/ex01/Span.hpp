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
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();
		void	addNumber(int n);

		template <typename T>
		void addArray(T begin, T end)
		{
			for (;begin < end && this->arr.size() < this->size; begin++)
				(this->arr).push_back(*begin);
		}

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



// ! Container properties
//	 ? Sequence
//	 		* Elements in sequence containers are ordered in a strict linear sequence. Individual elements are accessed by their position in this sequence.
//	 ? Dynamic array
//	 		* Allows direct access to any element in the sequence, and provides relatively fast addition/removal of elements at the end of the sequence.
//	 ? Allocator-aware
//	 		* The container uses an allocator object to dynamically handle its storage needs.