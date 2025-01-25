#include "Serializer.hpp"

int main(void)
{
	Data *data = new Data;
	data->product = "Kombucha";
	data->amount = 300;
	data->price = 999.9;
	data->available_flg = true;
	data->id = 123456789;

	std::cout << "DATA OUTPUT BEFORE Serializer" << std::endl;
	std::cout << data->product << std::endl;
	std::cout << data->amount << std::endl;
	std::cout << data->price << std::endl;
	std::cout << data->available_flg << std::endl;
	std::cout << data->id << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout << std::endl << "Deserialized data (new) made of Serialized Data" << std::endl;
	std::cout << serialized->product << std::endl;
	std::cout << serialized->amount << std::endl;
	std::cout << serialized->price << std::endl;
	std::cout << serialized->available_flg << std::endl;
	std::cout << serialized->id << std::endl;

	delete data;
	return (0);
}
