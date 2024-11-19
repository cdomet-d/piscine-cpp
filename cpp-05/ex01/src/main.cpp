/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 12:09:21 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testBureaucrats(void);
void testForms(void);

int main(void)
{
	testBureaucrats();
	testForms();

	std::cout << std::endl << "Trying to sign forms..." << std::endl;

	try
	{
		Form one = Form("A form", 10, 15);
		Form two = Form("Another form", 10, 15);
		Bureaucrat John = Bureaucrat("John", 5);
		Bureaucrat Jack = Bureaucrat("John", 50);

		one.beSigned(John);
		std::cout << one << std::endl;
		two.beSigned(Jack);
		std::cout << two << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
