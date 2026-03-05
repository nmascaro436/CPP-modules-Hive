#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
	T *_array;
	unsigned int _size;

	public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array &operator=(const Array& other);
	~Array();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp" // include here because compiler needs to see the full implementation of the template