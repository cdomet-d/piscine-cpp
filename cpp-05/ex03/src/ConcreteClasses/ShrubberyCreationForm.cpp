/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:33 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/25 10:33:47 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _name, const std::string _target)
	: AForm(_name, _target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &comp)
{
	AForm::operator=(comp);
	return *this;
}
/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void ShrubberyCreationForm::checkAuth(const short int expect, const short int got)
{
	if (!this->getSignedStatus())
		return throw ShrubberyCreationForm::FormNotSignedException();
	if (got > expect)
	{
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
	std::cout << "File [ " << this->getTarget() << " ] created and populated." << std::endl;
}
