#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <vector>
# include <deque>

class PmergeMe {
	private:
		std::vector<int> intVector;
		std::deque<int> intDeque;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		void intVectorPrinter();
		void intDequePrinter();
		void readInput(char **argv);
		template<typename T>
		void fordJohnsonSort(T &lst, int startIndex, int endIndex);
		void fordJohnsonSortWrapper();
		template<typename T>
		void mergeSublists(T &lst, int startIndex, int midIndex, int endIndex);
};

#endif