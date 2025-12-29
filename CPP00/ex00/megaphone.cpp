#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				char upper_value = toupper(argv[i][j]);
				std::cout << upper_value;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
