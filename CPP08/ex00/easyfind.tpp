#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& find, int search)
{
	for (typename T::iterator it = find.begin(); it != find.end(); it++) // loop through each element in find
	{
		if (*it == search)
			return it;
	}
	throw std::runtime_error("Element not found");
}
