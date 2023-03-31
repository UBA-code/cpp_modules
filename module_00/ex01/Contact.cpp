#include "Contact.hpp"

std::string Contact::get_value(int index)
{
	if (index == 0)
		return (this->firstName);
	else if (index == 1)
		return (this->lastName);
	else if (index == 2)
		return (this->nickName);
	else if (index == 3)
		return (this->phoneNumber);
	else if (index == 4)
		return ("no access");
	else if (index == 5 && this->filled)
		return ("filled");
	return ("null");
}

void Contact::set_value(int index, std::string value)
{
	if (index == 0)
		this->firstName = value;
	else if (index == 1)
		this->lastName = value;
	else if (index == 2)
		this->nickName = value;
	else if (index == 3)
		this->phoneNumber = value;
	else if (index == 4)
		this->secret = value;
	else if (index == 5)
		this->filled = 1;
}

Contact::Contact()
{
	this->filled = 0;
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->secret = "";
};
