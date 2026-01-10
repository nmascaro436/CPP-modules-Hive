#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "=== All Valid Complaint Levels ===" << std::endl;
	std::cout << "\nTest DEBUG:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\nTest INFO:" << std::endl;
	harl.complain("INFO");
	
	std::cout << "\nTest WARNING:" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\nTest ERROR:" << std::endl;
	harl.complain("ERROR");

	std::cout << "\n=== Invalid Complaint Levels ===" << std::endl;
	std::cout << "\nTest lowercase 'debug':" << std::endl;
	harl.complain("debug");
	
	std::cout << "\nTest empty string:" << std::endl;
	harl.complain("");
	
	std::cout << "\nTest random string 'HELLO':" << std::endl;
	harl.complain("HELLO");
	
	std::cout << "\nTest mixed case 'WaRnInG':" << std::endl;
	harl.complain("WaRnInG");

	std::cout << "\n=== Harl Complains Multiple Times ===" << std::endl;
	std::cout << "\nHarl is having a bad day..." << std::endl;
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("INFO");

	return 0;
}
