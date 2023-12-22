#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include "Data.hpp"

class Serialization {
	public:
		Serialization();
		~Serialization();
		Serialization &operator=(const Serialization& obj);
		Serialization(const Serialization& copy);

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

# endif