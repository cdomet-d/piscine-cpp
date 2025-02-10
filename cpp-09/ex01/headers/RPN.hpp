/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:26 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/10 16:24:56 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stdint.h>
#include <stack>
#include <string>

class RPN {
  public:
	/*                               ORTHODOX CLASS                           */
	RPN(void);
	RPN(const RPN &copy);
	~RPN(void);
	RPN &operator=(const RPN &copy);

	/*                               METHODS                                  */
	void compute(const std::string &expr);

	/*                               GETTERS                                  */
	int getResult();
	/*                               EXCEPTIONS                               */
	class UnexpectedToken : public std::exception {
	  public:
		const char *what() const throw();
	};
	class MissingOperands : public std::exception {
	  public:
		const char *what() const throw();
	};
	class DivisionByZero : public std::exception {
	  public:
		const char *what() const throw();
	};
	class MissingOperators : public std::exception {
	  public:
		const char *what() const throw();
	};

  private:
	std::stack< int > rpn;

	/*                               METHODS                                  */
	int result;
	bool isOperator(const char c);
	char addVal(char operand);
	bool opIsAllowed();
	int doOp(const char op);
};

#endif
