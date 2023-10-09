#pragma once
#include <iostream>

template <typename T>
class Array {
	private:
		T		*arr;
		size_t	n;
	public:
		Array() : arr(new T[1]), n(1){};
		Array(unsigned int i){
			if (i > 0)
			{
				this->n = i;
				this->arr = new T[i]();
			}
		};
		Array(Array &obj) {*this = obj;};
		Array& operator=(Array &obj)
		{
			if (this != &obj)
			{
				this->n = obj.n;;
				this->arr = new T[n];
				for (size_t i = 0; i < this->n; i++)
					this->arr[i] = obj.arr[i];
			}
			return (*this);
		};
		~Array(){delete[] this->arr;}

		// * member functions
		size_t	size() const {return this->n;}

		void	set_value(T &s)
		{
			for (size_t i = 0; i < this->n; i++)
				this->arr[i] = s;
		}

		void	set_value(T &s) const
		{
			(void)s;
		}

		void	print() const {
			for (size_t i = 0; i < this->n; i++)
				std::cout << this->arr[i] << "\n";
		};

		T& operator[](size_t index)
		{
			if (index >= this->n)
				throw (rangeOverflow());
			return (this->arr[index]);
		}

		T operator[](size_t index) const
		{
			if (index >= this->n)
				throw (rangeOverflow());
			return (this->arr[index]);
		}

		class rangeOverflow : public std::exception {
			const char* what() const throw() {
				return ("\033[0;31mOverflow detected !\033[0;37m\n");
			}
		};
};
