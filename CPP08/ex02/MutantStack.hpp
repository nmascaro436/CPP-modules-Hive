#pragma once
#include <iostream>
#include <stack>

/**
 * std::stack is a container adaptor, works like a stack of plates, we can only see what is
 * at the top, that's why it isn't iterable. It's built on top of std::deque (can also use
 * list or vector), and that is stored as a member object (container C).
 */

template <typename T>
class MutantStack: public std::stack<T> // stack is a template that can hold different types
{
	public:
	typedef typename std::deque<T>::iterator iterator; //creating an alias for the iterator that we have available in the deque container
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"