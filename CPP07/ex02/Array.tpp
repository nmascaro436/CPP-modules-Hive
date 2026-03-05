#include "Array.hpp"

template <typename T> Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n): _array(new T[n]), _size(n) {}

template <typename T> Array<T>::Array(const Array& other)
{
	T *copyArray = new T[other._size]; //create memory for the copy so it's independent
	for (int i = 0; i < other._size; i++)
		copyArray[i] = other._array[i];
	
	_array = copyArray;
	_size = other._size;
}
template <typename T> Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		T *copyArray = new T[other._size];
		for (int i = 0; i < other._size; i++)
			copyArray[i] = other._array[i];
	
		_array = copyArray;
		_size = other._size;
	}
	return (*this);
}

template <typename T> Array<T>::~Array()
{
	delete[] _array;
}

template <typename T> T& Array<T>::operator[](unsigned int index)
{
	if (index >= size())
		throw std::out_of_range("Index is out of bounds");
	return _array[index];
}

template <typename T> const T& Array<T>::operator[](unsigned int index) const
{

}

template <typename T> unsigned int Array<T>::size() const
{

}
