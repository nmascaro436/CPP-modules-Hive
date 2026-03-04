#pragma once
#include <iostream>

//templates allow us to write functions that work with many types

template <typename T> void swap(T& a, T& b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T> T const& min(T const& a, T const& b)
{
	return a < b ? a : b;
}

template <typename T> T const& max(T const& a, T const& b)
{
	return a > b ? a : b;
}
