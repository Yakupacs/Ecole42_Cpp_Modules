#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
	private:
		std::vector<int> V;
		unsigned int N;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
	
		class SpanAlreadyFull: public std::exception {
			public:
				const char *what() const throw() {
					return ("Error: Span is already full!");
				}
		};
		class NotEnoughNumbers: public std::exception {
			public:
				const char *what() const throw() {
					return ("Error: Not enough numbers stored!");
				}
		};
};

#endif