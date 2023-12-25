#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <stdexcept>

class RPN {
	private:
		std::stack<int> operationsStack;
		int isOperand(const std::string &token);
		int performOperation(const std::string &token);
	public:
		RPN();
		~RPN();
		RPN(const std::string &expression);
		RPN(const RPN& other);
		RPN &operator=(const RPN &other);
		int parseExpression(const std::string &expression);
};

#endif