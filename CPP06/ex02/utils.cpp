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
//dynamic_cast on a pointer returns nullptr, no exception
void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) // if p points to A
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

//dynamic_cast on a reference throws bad_cast exception, so we use the try/catch
void identify(Base& p) 
{
    try {
        (void)dynamic_cast<A&>(p); // try to cast p to &A, and see if it succeeds
        std::cout << "A\n";
    } catch(...) { // did the cast fail for any reason?
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "B\n";
        } catch(...) {
            std::cout << "C\n";
        }
    }
}
