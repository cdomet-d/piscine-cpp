/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:31 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/13 15:24:31 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

// pop : removes top element
// push : insert element at the top

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

RPN::RPN(void) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &comp)
{
	// copy instructions
	(void)comp;
	return *this;
}

int RPN::getResult()
{
	return result;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

bool RPN::opIsAllowed()
{
	if (rpn.size() >= 2)
		return true;
	return false;
}
bool RPN::isOperator(char c)
{
	char op[5] = "+-*/";

	for (uint8_t i = 0; op[i]; ++i) {
		if (c == op[i])
			return true;
	}
	return false;
}
bool RPN::isDigit(char c)
{
	char digit[11] = "0123456789";
	for (uint8_t i = 0; digit[i]; ++i) {
		if (c == digit[i])
			return true;
	}
	return false;
}
int RPN::doOp(char op)
{
	if (!opIsAllowed())
		throw MissingOperands();

	int b = rpn.top();
	rpn.pop();
	int a = rpn.top();
	rpn.pop();

	switch (op) {
	case '*':
		return a * b;
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '/':
		if (b == 0)
			throw DivisionByZero();
		return a / b;
	default:
		throw std::exception();
	}
}

void RPN::compute(std::string expr)
{
	for (std::string::iterator it = expr.begin(); it != expr.end(); ++it) {
		if (*it == ' ')
			continue;
		else if (isOperator(*it)) {
			rpn.push(doOp(*it));
		} else if (isDigit(*it)) {
			rpn.push(*it - '0');
		} else {
			throw UnexpectedToken();
		}
	}
	if (rpn.size() != 1)
		throw MissingOperators();
	result = rpn.top();
	rpn.pop();
}

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

const char *RPN::UnexpectedToken::what() const throw()
{
	return "Illegal character in input";
}

const char *RPN::DivisionByZero::what() const throw()
{
	return "Illegal division ( / 0)";
}

const char *RPN::MissingOperands::what() const throw()
{
	return "Not enough operands";
}

const char *RPN::MissingOperators::what() const throw()
{
	return "Not enough operators";
}