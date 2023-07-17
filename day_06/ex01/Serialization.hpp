#pragma once

class Serialization {
	private:
		Serialization();
		Serialization(Serialization& obj);
		Serialization& operator=(Serialization& obj);
	public:
		static uintptr_t serialize(Data* ptr);
};