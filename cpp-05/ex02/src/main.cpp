/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/25 15:00:17 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <signal.h>

void testPresidentialForms(void);
void testRobotomyRequestForm(void);
void testShrubberyForm(void);

int main(int ac, char *av[])
{
	std::string input;

	if (ac != 2)
	{
		std::cout << "To test Presidential Forms: type 1" << std::endl
				  << "To test Robotomy Forms: type 2" << std::endl
				  << "To test Shrubbery Forms: type 3" << std::endl;
		return (1);
	}
	input = av[1];
	if (input.compare("1") == 0)
		testPresidentialForms();
	else if (input.compare("2") == 0)
		testRobotomyRequestForm();
	else if (input.compare("3") == 0)
		testShrubberyForm();
	else
		std::cout << "/!\\ Unknown command: " << input << std::endl;
	return (0);
}
