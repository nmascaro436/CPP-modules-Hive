#include "Array.hpp"

int main ()
{
	std::cout << "EMPTY ARRAY TEST\n";
	Array<int> emptyArray;
	std::cout << "Size: " << emptyArray.size() << '\n';

	std::cout << "ARRAY WITH SOME SIZE TEST\n";
	Array<int> array(5);
	std::cout << "Size: " << array.size() << '\n';
	for (unsigned int i = 0; i < array.size(); i++)
		array[i] = i;
	for (unsigned int i = 0; i < array.size(); i++)
		std::cout << array[i] << '\n';
	
	std::cout << "OUT OF BOUNDS TEST\n";
	Array<int> exceptionArray(6);	
	try
	{
		std::cout << exceptionArray[7] << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	std::cout << "COPY CONSTRUCTOR TEST\n";
	Array<int> copyTest(array);
	copyTest[0] = 100;
	std::cout << "Original array: " << array[0] << '\n';
	std::cout << "Copied array: " << copyTest[0] << '\n';
	
	std::cout << "COPY ASSIGNMENT TEST\n";
	Array<int> assigned;
	assigned = array;
	assigned[1] = 14;
	std::cout << "Original array: " << array[1] << '\n';
	std::cout << "Assigned array: " << assigned[1] << '\n';

	std::cout << "STRING ARRAY TEST\n";
	Array<std::string> words(4);
	words[0] = "Hello";
	words[1] = "Hive";
	words[2] = "Helsinki";
	words[3] = "Students";
	for (unsigned int i = 0; i < words.size(); i++)
		std::cout << words[i] << '\n';
	
	std::cout << "CONST ARRAY TEST\n";
	const Array<int> constArray(5);
	for (unsigned int i = 0; i < constArray.size(); i++)
		std::cout << constArray[i] << '\n';
}
