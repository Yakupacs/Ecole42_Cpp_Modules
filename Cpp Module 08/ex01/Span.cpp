#include "Span.hpp"

Span::Span() {
	this->N = 0;
	this->V = std::vector<int>();
}
Span::Span(unsigned int N) {
	this->N = N;
	this->V = std::vector<int>();
}
Span::Span(const Span &copy) {
	*this = copy;
}
Span &Span::operator=(const Span &copy) {
	this->V = copy.V;
	this->N = copy.N;
	return *this;
}
Span::~Span() {}
void Span::addNumber(int n) {
	if (this->V.size() == this->N) 
		throw SpanAlreadyFull();
	this->V.push_back(n);
}
int Span::shortestSpan() {
	if (this->V.size() <= 1)
		throw NotEnoughNumbers();
	std::sort(V.begin(), V.end());
	int shortest = V[1] - V[0];
	for (int i = 2; i < V.size(); ++i) {
		int span = V[i] - V[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}
int Span::longestSpan() {
	if (this->V.size() <= 1)
		throw NotEnoughNumbers();
	std::sort(V.begin(), V.end());
	return (V.back() - V.front());
}
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	while (begin != end)
		addNumber(*begin++);
}