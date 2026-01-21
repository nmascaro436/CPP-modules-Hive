#include "Sed.hpp"

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	if (s1.empty())
	{
		std::cout << "Search string can't be empty." << std::endl;
		return;
	}
	std::ifstream infile(filename); // open file for read only, file needs to exist already
	if (!infile)
	{
		std::cout << "Can't open input file." << std::endl;
		return;
	}
	std::ofstream outfile(std::string(filename) + ".replace"); // create file for writing
	if (!outfile)
	{
		std::cout << "Can't create output file." << std::endl;
		return;
	}
	
	std::string line;
	while (std::getline(infile, line)) // go line by line and store in "line"
	{
		size_t position = 0; // beginning of line
		while ((position = line.find(s1, position)) != std::string::npos) // looks for s1 starting at index position, if found returns index, if not returns npos
		{
			line = line.substr(0, position) + s2 + line.substr(position + s1.length()); // copy until the position of s1, add s2 after it and copy what was after the s1
			position += s2.length(); //move forward
		}
		outfile << line << '\n'; // write into outfile with a newline
	}
	infile.close();
	outfile.close();
}
