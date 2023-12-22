#include "Serialization.hpp"

int main() {
	Serialization serializer;
	Data* data = new Data;

	data->fullName = "Yakup Açış";
	data->age = 23;
	data->height = 1.78f;
	data->weight = 65.3;

	std::cout << "data->fullName: " << data->fullName << std::endl;
	std::cout << "data->age: " << data->age << std::endl;
	std::cout << "data->height: " << data->height << std::endl;
	std::cout << "data->weight: " << data->weight << std::endl;

	uintptr_t uni = serializer.serialize(data);

	std::cout << "uintptr_t: " << uni << std::endl;

	Data *new_data = serializer.deserialize(uni);

	std::cout << "new_data->fullName: " << new_data->fullName << std::endl;
	std::cout << "new_data->age: " << new_data->age << std::endl;
	std::cout << "new_data->height: " << new_data->height << std::endl;
	std::cout << "new_data->weight: " << new_data->weight << std::endl;

	delete data;
}