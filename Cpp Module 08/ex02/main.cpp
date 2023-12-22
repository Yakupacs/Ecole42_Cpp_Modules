#include "MutantStack.hpp"

int main(void) {
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3); 
	mstack.push(4); 
	mstack.push(5);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
	    std::cout << "MutantStack<int> -> " << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack);

	int size = s.size();
	for (int i = 0; i < size; i++) {
		std::cout << "std::stack<int> -> " << s.top() << std::endl;
		s.pop();
	}

	return 0;
}