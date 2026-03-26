#pragma once
#include <iostream>
#include <stack>

/**
 * std::stack is a container adaptor, works like a stack of plates, we can only see what is
 * at the top, that's why it isn't iterable. It's built on top of std::deque, and that is stored as a member object (container c).
 * MutantStack is a template class that inherits from another template class (stack).
 */

template <typename T>
class MutantStack: public std::stack<T> // stack is a template that can hold different types
{
	public:
	MutantStack();	
	MutantStack(const MutantStack& other);
	MutantStack &operator=(const MutantStack& other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator; //creating an alias for the iterator used inside the stack
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"