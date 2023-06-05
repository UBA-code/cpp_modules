#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "iostream"
#include <iomanip>

class PhoneBook{
	private:
		int		i;
		Contact contacts[8];
	public:
		void	add();
		void	search();
		void	list(int index);
	PhoneBook();
};

bool check_empty(std::string str);
void	printStr(std::string str);


#endif