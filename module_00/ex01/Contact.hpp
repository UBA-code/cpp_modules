#ifndef Contact_HPP
#define Contact_HPP

#include "stdio.h"
#include "iostream"
#include <ctype.h>

class Contact{
	private:
		bool		filled;
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string secret;
	public:
		std::string get_value(int index);
		void		set_value(int index, std::string value);
	Contact();
};

#endif