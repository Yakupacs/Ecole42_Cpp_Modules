#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {
	while (!this->operationsStack.empty())
		this->operationsStack.pop();
}
RPN::RPN(const std::string &expression) {
	try {
		int result = parseExpression(expression);
		this->operationsStack.push(result);
	} catch (const std::exception &error) {
		std::cerr << error.what() << std::endl;
	}
}
RPN::RPN(const RPN &other) {
	this->operationsStack = other.operationsStack;
}
RPN &RPN::operator=(const RPN &other) {
	if (this == &other)
		return (*this);
	this->operationsStack = other.operationsStack;
	return (*this);
}
int RPN::isOperand(const std::string &token) {
	if ((token != "+") && (token != "-") && (token != "*") && (token != "/"))
		return (1);
	return (0);
}
int RPN::performOperation(const std::string &token) {
	int operation2 = this->operationsStack.top();
	this->operationsStack.pop();

	int operation1 = this->operationsStack.top();
	this->operationsStack.pop();

	if (token == "+")
		return (operation1 + operation2);
	else if (token == "-")
		return (operation1 - operation2);
	else if (token == "*")
		return (operation1 * operation2);
	else if (token == "/") {
		if (operation2 == 0)
			throw(std::runtime_error("Error: Division by zero"));
		return (operation1 / operation2);
	}
	throw(std::invalid_argument("Error: Invalid operator"));
}
int RPN::parseExpression(const std::string &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isOperand(token)) {
			int operand;
			std::istringstream(token) >> operand;
			this->operationsStack.push(operand);
		} else {
			if (this->operationsStack.size() < 2)
				throw(std::invalid_argument("Error: Insufficient operands for operator " + token));
			int result = performOperation(token);
			this->operationsStack.push(result);
		}
	}
	if (this->operationsStack.size() == 1)
		return (this->operationsStack.top());
	else
		throw std::invalid_argument("Error: Invalid expression");
}