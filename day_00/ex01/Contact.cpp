#include "Contact.hpp"

std::string Contact::get_value(int index)
{
	std::string arr[] = {this->firstName, this->lastName, this->nickName, this->phoneNumber, this->secret};
	int i;
	for (i = 0; i < 5; i++)
		if (index == i)
			return (arr[i]);
	if (index == 5 && this->filled)
		return ("filled");
	return ("null");
}

void Contact::set_value(int index, std::string value)
{
	std::string *arr[] = {&this->firstName, &this->lastName, &this->nickName, &this->phoneNumber, &this->secret};
	for (int i = 0; i < 5; i++)
		if (index == i)
			*arr[i] = value;
	if (index == 5)
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
