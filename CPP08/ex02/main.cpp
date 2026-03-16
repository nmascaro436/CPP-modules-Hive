#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5); 
	mstack.push(17);

	std::cout << mstack.top() << std::endl; // prints top element
	mstack.pop(); // removes top element
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin(); // creates iterators
	MutantStack<int>::iterator ite = mstack.end();
	++it; // move forward
	--it; // move backwards, testing that iterators work
	while (it != ite)
	{
		std::cout << *it << std::endl; // getting the value of the iterator
		++it;
	}	
	std::stack<int> s(mstack); //showing that MutantStack is same as stack
	return 0;
}
/**
#include <list>
int main()
{
 	std::list<int> mstack;
	mstack.push_back(5); 
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl; // prints top element
	mstack.pop_back(); // removes top element
	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin(); // creates iterators
	std::list<int>::iterator ite = mstack.end();
	++it; // move forward
	--it; // move backwards, testing that iterators work
	while (it != ite)
	{
		std::cout << *it << std::endl; // getting the value of the iterator
		++it;
	}	
	return 0;
}
*/
