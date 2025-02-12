/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:33 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:25:02 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _target)
	: AForm("Shrubbery Creation Form", _target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
	: AForm(rhs)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
}
/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void ShrubberyCreationForm::checkAuth(const short int expect,
									  const short int got)
{
	if (!this->getSignedStatus())
		return throw ShrubberyCreationForm::FormNotSignedException();
	if (got > expect) {
		std::cout << "Couldn't execute ShrubberyCreationForm: expected grade "
				  << expect << " or higher, got: " << got << std::endl;
		return throw ShrubberyCreationForm::GradeTooLowException();
	}
}

// Required grades: sign 145, exec 137
void ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	this->checkAuth(SHRUBBERY_EXEC_GRADE, executor.getGrade());
	std::ofstream destFile(this->getTarget().c_str());
	if (!destFile.is_open())
		return throw std::ios_base::failure("Could not open destination file");
	destFile << "               ,@@@@@@@," << std::endl
			 << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
			 << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
			 << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
			 << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
			 << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
			 << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
			 << "       |o|        | |         | |" << std::endl
			 << "       |.|        | |         | |" << std::endl
			 << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	destFile.close();
	std::cout << "File [ " << this->getTarget() << " ] created and populated."
			  << std::endl;
}
