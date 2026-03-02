#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	srand(time(NULL));
	std::cout << "POINTER IDENTIFICATION TESTS \n";
	for (int i = 0; i < 10; i++)
	{
		Base *random = generate();
		identify(random);
		delete random;
	}

	std::cout << "REFERENCE IDENTIFICATION TESTS \n";

	A a;
	B b;
	C c;

	identify(a); 
	identify(b);
	identify(c);
}