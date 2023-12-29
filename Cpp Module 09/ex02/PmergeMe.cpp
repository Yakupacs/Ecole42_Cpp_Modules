#include "PmergeMe.hpp"
PmergeMe::PmergeMe() { }
PmergeMe::~PmergeMe() { }
PmergeMe::PmergeMe(const PmergeMe &other) {
	this->intVector = other.intVector;
	this->intDeque = other.intDeque;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->intVector = other.intVector;
		this->intDeque = other.intDeque;
	}
	return (*this);
}

void PmergeMe::intVectorPrinter() {
	for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void PmergeMe::intDequePrinter() {
	for (std::deque<int>::iterator it = intDeque.begin(); it != intDeque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return ;
}

void PmergeMe::readInput(char **argv) {
	for (int i = 1; argv[i]; i++) {
		this->intVector.push_back(std::atoi(argv[i]));
		this->intDeque.push_back(std::atoi(argv[i]));
	}
}

void PmergeMe::fordJohnsonSortWrapper() {
	std::cout << "Before: ";
	this->intVectorPrinter();
	clock_t start = clock();
	this->fordJohnsonSort(this->intVector, 0, this->intVector.size() - 1);
	clock_t stop = clock();
	std::cout << "After: ";
	this->intVectorPrinter();
	double duration = ((stop - start) / (double)CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of " << this->intVector.size() << " elements with std::vector : " << duration << " us" << std::endl;

	std::cout << "Before: "; 
	this->intDequePrinter();
	start = clock();
	this->fordJohnsonSort(this->intDeque, 0, this->intDeque.size() - 1);
	stop = clock();
	std::cout << "After: ";
	this->intDequePrinter();
	duration = ((stop - start) / (double)CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of " << this->intDeque.size() << " elements with std::deque : " << duration << " us" << std::endl;
}

template<typename T>
void PmergeMe::fordJohnsonSort(T &lst, int startIndex, int endIndex) {
	int midIndex;

	if (startIndex != endIndex) {
		midIndex = startIndex + ((endIndex - startIndex) / 2);
		fordJohnsonSort(lst, startIndex, midIndex);
		fordJohnsonSort(lst, midIndex + 1, endIndex);
		mergeSublists(lst, startIndex, midIndex, endIndex);
	}
}

template<typename T>
void PmergeMe::mergeSublists(T &lst, int startIndex, int midIndex, int endIndex) {
	int leftIndex = startIndex;
	int rightIndex = midIndex + 1;
	int tempIndex = 0;
	std::vector<int> temp(endIndex - startIndex + 1);

	while ((leftIndex <= midIndex) && (rightIndex <= endIndex)) {
		if (lst[leftIndex] <= lst[rightIndex]) {
			temp[tempIndex] = lst[leftIndex];
			tempIndex++;
			leftIndex++;
		}
		else {
			temp[tempIndex] = lst[rightIndex];
			tempIndex++;
			rightIndex++;
		}
	}

	while (leftIndex <= midIndex)
		temp[tempIndex++] = lst[leftIndex++];

	while (rightIndex <= endIndex)
		temp[tempIndex++] = lst[rightIndex++];

	for (int p = 0; p < tempIndex; p++)
		lst[startIndex + p] = temp[p];
}
