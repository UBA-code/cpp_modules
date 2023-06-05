#pragma once

#include "iostream"

class Brain {
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(std::string ideas[100]);
		Brain(const Brain& obj);
		Brain& operator=(const Brain& obj);
		~Brain();
};
