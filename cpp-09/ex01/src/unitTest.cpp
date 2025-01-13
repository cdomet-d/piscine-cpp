/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:21:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/13 15:24:49 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "unitTest.hpp"
#include "RPN.hpp"

void testValid()
{
	{
		std::cout << "Valid expressions" << std::endl;

		std::map< std::string, int > validOp;
		RPN rpn;

		validOp["7 2 + 3 * 4 -"] = 23;
		validOp["5 6 * 8 - 2 /"] = 11;
		validOp["1 2 + 3 * 4 + 5 *"] = 65;
		validOp["8 2 * 3 + 4 * 5 -"] = 71;
		validOp["2 3 + 4 * 5 - 5 /"] = 3;
		validOp["8 4 / 3 * 2 + 7 -"] = 1;
		validOp["9 3 / 2 * 4 + 6 -"] = 4;
		validOp["1 2 + 3 + 4 + 5 *"] = 50;
		validOp["8 9 + 5 * 5 *"] = 425;
		for (std::map< std::string, int >::iterator it = validOp.begin();
			 it != validOp.end(); ++it) {
			VALID_EXPR(rpn, it->first, it->second);
		}
	}
}

void testInvalid()
{
	std::cout << "\nException testing" << std::endl;
	{
		RPN rpn;
		INVALID_EXPR("5 2 * 3 + 4 * 0 /", rpn.compute("5 2 * 3 + 4 * 0 /"),
					 RPN::DivisionByZero);
	}
	{
		RPN rpn;
		INVALID_EXPR("7 2 + 3e * 4 -", rpn.compute("7 2 + 3e * 4 -"),
					 RPN::UnexpectedToken);
	}
	{
		RPN rpn;
		INVALID_EXPR("5 *", rpn.compute("5 *"), RPN::MissingOperands);
	}
	{
		RPN rpn;
		INVALID_EXPR("1 / + 3 * 4 + 5 *", rpn.compute("1 / + 3 * 4 + 5 *"),
					 RPN::MissingOperands);
	}
	{
		RPN rpn;
		INVALID_EXPR("", rpn.compute(""), RPN::MissingOperators);
	}
	{
		RPN rpn;
		INVALID_EXPR("8 9 + 5 5 *", rpn.compute(""), RPN::MissingOperators);
	}
}