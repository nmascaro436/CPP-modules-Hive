#include "iter.hpp"

template <typename T> void print(const T& result)
{
	std::cout << result << '\n';
}

template <typename T> void increment(T& number)
{
	number++;
}

template <typename T> void convertToUpper(T& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
		std::cout << str[i];
	}
	std::cout << '\n';
}
int main()
{
	int intArray[] = {1,2,3,4,5};
	
	std::cout << "Numbers before increment\n";
	iter(intArray, 5, print<int>);

	std::cout << "Numbers after increment\n";
	iter(intArray, 5, increment<int>);
	iter(intArray, 5, print<int>);

	std::string words[] = {"hello", "this", "is", "something"};
	
	std::cout << "Words before modifying\n";
	iter(words, 4, print<std::string>);

	std::cout << "Words after modifying\n";
	iter(words, 4, convertToUpper<std::string>);


	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};

	std::cout << "Float numbers before increment\n";
	iter(floatArray, 4, print<float>);

	std::cout << "Float numbers after increment\n";
	iter(floatArray, 4, increment<float>);
	iter(floatArray, 4, print<float>);

	char charArray[] = {'a', 'b', 'c', 'd'};
	std::cout << "Chars before modifying\n";
	iter(charArray, 4, print<char>);

	std::cout << "Chars after modifying by incrementing \n";
	iter(charArray, 4, increment<char>);
	iter(charArray, 4, print<char>);

	return 0;
}

