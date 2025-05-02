/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:50:30 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int main(int ac, char *av[]) {
	if (ac != 3) {
		std::cout
			<< "Expected two arguments:\n argument 1 should be requested form: <robotomy request>, \
<presidential request> or <shrubbery request>\n argument 2 should be the target of that form"
			<< std::endl;
		return 1;
	}
	try {
		Intern intern;
		Bureaucrat drone("Corpodrone", 1);
		AForm *form;

		form = intern.makeForm(av[1], av[2]);
		drone.signForm(*form);
		form->execute(drone);
		delete form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
