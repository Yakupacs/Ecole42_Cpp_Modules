#include "PmergeMe.hpp"
PmergeMe::PmergeMe() { }
PmergeMe::~PmergeMe() { }
PmergeMe::PmergeMe(const PmergeMe &other) {
	this->intVector = other.intVector;
	this->intDeque = other.intDeque;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
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
	for (int i = 1; argv[i]; i++)
	{
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

	if (startIndex != endIndex)
	{
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

/*
mergeSublists is called multiple times during the merge sort process. Let me provide a more detailed explanation, including the second call to mergeSublists in step 5.

    Initial Call: fordJohnsonSort([1, 3, 5, 2, 4], 0, 4)
        Divides the list into two sublists: [1, 3] and [5, 2, 4]
        Calls fordJohnsonSort([1, 3], 0, 1) and fordJohnsonSort([5, 2, 4], 2, 4)

    Left Sublist [1, 3] (sublist indices 0 to 1):
        Already sorted; no further recursive calls or merges needed.

    Right Sublist [5, 2, 4] (sublist indices 2 to 4):
        Divides into two sublists: [5] and [2, 4]
        Calls fordJohnsonSort([5], 2, 2) and fordJohnsonSort([2, 4], 3, 4)

    Sublist [5] (sublist index 2):
        Already sorted; no further recursive calls or merges needed.

    Sublist [2, 4] (sublist indices 3 to 4):
        Divides into individual elements, which are already sorted.

    Merging Step 1: mergeSublists([2, 4], 3, 4)
        Merging the sorted sublists [2] and [4] into [2, 4].
        Resulting sublist: [2, 4]

    Merging Step 2: mergeSublists([5], 2, 2) and mergeSublists([2, 4], 3, 4)
        Merging the sorted sublists [5] and [2, 4] into a single sorted sublist.
        Resulting sublist: [2, 4, 5]

    Final Merge: mergeSublists([1, 3], 0, 1) and mergeSublists([2, 4, 5], 2, 4)
        Merging the sorted sublists [1, 3] and [2, 4, 5] into a single sorted list.
        Resulting sorted list: [1, 2, 3, 4, 5]

In this explanation, mergeSublists is indeed called twice during the merging process. The second call occurs when merging the sorted sublists [5] and [2, 4] into a single sorted sublist. This results in the final sorted list [1, 2, 3, 4, 5].
User
I have a question about step 8
Wouldnt merging [1,3] and [2,4,5] result in [1,3,2,4,5] ?
ChatGPT

I see where the confusion might arise. In the merge step between [1, 3] and [2, 4, 5], the comparison between elements ensures that the sorting order is maintained. Let me break down the process more explicitly for step 8:

    Sublist [1, 3] (indices 0 to 1) and Sublist [2, 4, 5] (indices 2 to 4):
        Compare the first elements of both sublists: 1 and 2.
            Since 1 is smaller, it comes first in the merged list: [1].
            Move to the next element in the [1, 3] sublist.
        Compare the next elements: 3 and 2.
            Since 2 is smaller, it comes next in the merged list: [1, 2].
            Move to the next element in the [2, 4, 5] sublist.
        Compare the next elements: 3 and 4.
            Since 3 is smaller, it comes next in the merged list: [1, 2, 3].
            Move to the next element in the [1, 3] sublist.
        The [1, 3] sublist is now empty. Add the remaining elements from the [2, 4, 5] sublist to the merged list.
            Merged list: [1, 2, 3, 4, 5].

By comparing and merging the elements in the correct order, the merged list becomes [1, 2, 3, 4, 5], which is the sorted result of merging [1, 3] and [2, 4, 5].
*/