#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string fileName = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		int s1_len = s1.length();
		int s2_len = s2.length();
		size_t position = 0;
		std::string line;

		if (fileName.empty() || s1.empty() || s2.empty())
		{
			std::cout << "Error! Arguments can't be empty." << std::endl;
			return (2);
		}

		std::ifstream readFile(fileName);
		if (!readFile.is_open())
		{
			std::cout << "Error! The file didn't find." << std::endl;
			return (3);
		}

		std::ofstream writeFile((fileName + ".replace"), std::ios::trunc);
		if (!writeFile.is_open())
		{
			std::cout << "Error! The file didn't open." << std::endl;
			return (4);
		}

		while (std::getline(readFile, line))
		{
			position = 0;
			while ((position = line.find(s1, position)) != std::string::npos)
			{
				line.erase(position, s1_len);
				line.insert(position, s2);
				position = position + s2_len;
			}
			writeFile << line << std::endl;
		}
	}
	else
	{
		std::cout << "Error! The argument is not valid." << std::endl << "Please use ./program [fileName] [search] [replace]" << std::endl;
		return (1);
	}
	return (0);
}