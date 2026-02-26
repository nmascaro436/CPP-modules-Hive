#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
    } catch(...) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        } catch(...) {
            std::cout << "C\n";
        }
    }
}
