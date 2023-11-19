#pragma once
#include "iostream"
#include "stack"
#include "iterator"
#include <deque>

template < class T, class Container=std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(){};
		MutantStack(const MutantStack& obj) : std::stack<T, Container>(obj){};
		MutantStack& operator=(const MutantStack& obj){
			std::stack<T, Container>::operator=(obj);
			return (*this);
		};
		~MutantStack(){};
		typedef typename Container::iterator iterator;
		iterator begin(){return this->c.begin();};
		iterator end(){return this->c.end();};
};
