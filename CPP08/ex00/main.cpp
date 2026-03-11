#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5};
    std::list<int> l = {10, 20, 30, 40, 50};
    std::deque<int> d = {100, 200, 300, 400, 500};
    std::vector<int> empty;

    // found
    try
	{ std::cout << *easyfind(v, 4) << std::endl; }
    catch (std::exception& e)
	{ std::cout << e.what() << std::endl; }

    // not found
    try
	{ std::cout << *easyfind(v, 99) << std::endl; }
    catch (std::exception& e)
	{ std::cout << e.what() << std::endl; }

    // empty container
    try
	{ std::cout << *easyfind(empty, 1) << std::endl; }
    catch (std::exception& e)
	{ std::cout << e.what() << std::endl; }

    // list
    try 
	{ std::cout << *easyfind(l, 30) << std::endl; }
    catch (std::exception& e)
	{ std::cout << e.what() << std::endl; }

    // deque
    try
	{ std::cout << *easyfind(d, 500) << std::endl; }
    catch (std::exception& e)
	{ std::cout << e.what() << std::endl; }

    return 0;
}