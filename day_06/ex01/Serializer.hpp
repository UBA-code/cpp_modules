#pragma once
#include "Data.hpp"
#include "stdint.h"

class Serializer {
	private:
		Serializer();
		Serializer(Serializer& obj);
		Serializer& operator=(Serializer& obj);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
