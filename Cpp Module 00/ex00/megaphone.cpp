#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		int i;
		int j;

		i = 0;
		while (av[++i])
		{
			j = 0;
			while (av[i][j])
				std::cout << (char)std::toupper(av[i][j++]);
		}
		std::cout << std::endl;
	}
	return (0);
}