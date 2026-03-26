#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other): std::stack<T>(other) {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin(); // deque's begin() is the first pushed element (bottom of stack)
}
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}
