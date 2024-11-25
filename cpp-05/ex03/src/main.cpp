/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/25 11:17:26 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <signal.h>

void testPresidentialForms(void);
void testRobotomyRequestForm(void);
void testShrubberyCreation(void);

int main(void)
{
	Intern patrick;
	Bureaucrat leader("emily", 1);
	AForm *form;

	form = patrick.makeForm("robotomy", "adam smasher");
	leader.signForm(*form);
	form->execute(leader);
}
