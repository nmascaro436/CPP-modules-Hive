#include "iter.hpp"

template <typename T> void print(const T& result)
{
	std::cout << result << '\n';
}
int main()
{
	int intArray[] = {1,2,3,4,5};

	iter(intArray, 5, print<int>);

	return 0;
}

