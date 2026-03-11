#pragma once
#include <iostream>

/**
 * STL is a library that has 3 components:
 * -Containers: hold and organize data. Some of them are vectors, array, map, set, list.
 * -Algorithms: perform actions like sorting or searching on the data
 * -Iterators: help go through the data in containers one by one
 */
template <typename T>
typename T::iterator easyfind(T& find, int search); // iterator belongs to the T container, so it gets us the position of what we're looking for (it's a pointer to the element)

#include "easyfind.tpp"