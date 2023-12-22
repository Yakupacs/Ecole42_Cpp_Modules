#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include <vector>

class IsNotFound: public std::exception {
	public:
		const char *what() const throw() {
			return ("Not found in container!");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int number) {
	typename T::iterator it = find(container.begin(), container.end(), number);

	if (it == container.end())
		throw IsNotFound();
	return (it);
}

#endif