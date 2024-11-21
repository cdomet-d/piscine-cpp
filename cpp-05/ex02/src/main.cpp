/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/21 16:47:57 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <signal.h>

void testPresidentialForms(void);
void testRobotomyRequestForm(void);
void testShrubberyCreation(void);

// argument of type "int *" is incompatible with parameter of type "" (aka "void (*)(int)")C/C++(167)
bool sig = false;

void sigHandler(int signum){
	(void)signum;
	sig = true;
}
int main(void)
{
	std::string input;

	while (1)
	{
		std::cout << "To test Presidential Forms: type 1" << std::endl;
		std::cout << "To test Robotomy Forms: type 2" << std::endl;
		std::cout << "To test Shrubbery Forms: type 3" << std::endl;
		std::cout << "To exit: type exit" << std::endl;
		signal(SIGINT, sigHandler);
		getline(std::cin, input, '\n');
		if (sig == true)
			break;
		if (std::cin.eof() == true)
			return (1);
		else if (input.compare("1") == 0)
			testPresidentialForms();
		else if (input.compare("2") == 0)
			testRobotomyRequestForm();
		else if (input.compare("3") == 0)
			testShrubberyCreation();
		else if (input.compare("exit") == 0)
			break;
		else
			std::cout << "/!\\ Unknown command: " << input << std::endl;
	}
}
