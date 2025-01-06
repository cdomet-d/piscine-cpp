/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:26 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/06 17:51:29 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stdint.h>
#include <stack>
#include <string>

class RPN
{
public:
	/*                               ORTHODOX CLASS                           */
	RPN(void);
	RPN(const RPN &copy);
	~RPN(void);
	RPN &operator=(const RPN &copy);

	/*                               METHODS                                  */
	bool evaluateExpression(std::string expression);
	
	/*                               GETTERS                                  */
	
	/*                               SETTERS                                  */
private:
	std::stack<char> rpn;

	/*                               METHODS                                  */
	bool isOperator(char current);
};

#endif
