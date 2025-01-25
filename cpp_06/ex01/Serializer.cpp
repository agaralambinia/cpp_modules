#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &a)
{
	*this = a;
}


Serializer &Serializer::operator=(Serializer const &a)
{
	if (this != &a) {}
	return (*this);
}

Serializer::~Serializer(void) {}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
