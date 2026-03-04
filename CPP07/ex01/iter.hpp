#pragma once
#include <iostream>
#include <cctype>

template <typename T, typename F> void iter(T *array, const int len, F function)
{
	for (int i = 0; i < len; i++)
	{
		function(array[i]);
	}
}