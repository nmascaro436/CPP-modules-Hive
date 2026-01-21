#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of parameters. Only 3 needed!" << std::endl;
		return 1;
	}
	replaceInFile(argv[1], argv[2], argv[3]);
	return 0;
}
