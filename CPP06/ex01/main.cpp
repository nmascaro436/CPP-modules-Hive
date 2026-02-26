#include "Serializer.hpp"

int main()
{
	Data data;
	data.age = 26;
	data.name = "Nuria";
	data.id = 12345678911111;

	std::cout << "DATA VALUES BEFORE SERIALIZING \n";
	std::cout << "Age: " << data.age << '\n';
	std::cout << "Name: " << data.name << '\n';
	std::cout << "Id: " << data.id << '\n';
	std::cout << "Pointer address: " << &data << '\n';
	std::cout << '\n';

	std::cout << "DATA VALUES DURING SERIALIZING \n";
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Age: " << data.age << '\n';
	std::cout << "Name: " << data.name << '\n';
	std::cout << "Id: " << data.id << '\n';
	std::cout << "Serialized pointer: " << serialized << '\n';
	std::cout << '\n';
	
	std::cout << "DATA VALUES AFTER SERIALIZING \n";
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Age: " << deserialized->age << '\n';
	std::cout << "Name: " << deserialized->name << '\n';
	std::cout << "Id: " << deserialized->id << '\n';
	std::cout << "Pointer address: " << deserialized << '\n';
}
