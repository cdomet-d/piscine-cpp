/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:14:32 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 14:52:30 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	short int grade;

public:
	/*                               EXCEPTIONS                               */
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	/*                               ORTHODOX CLASS                           */
	Bureaucrat(void);
	Bureaucrat(const std::string _name, short int _grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);
	Bureaucrat &operator=(const Bureaucrat &copy);

	/*                               METHODS                                  */
	void upgrade(void);
	void downgrade(void);
	void signForm(Form &toBeSigned);

	/*                               GETTERS                                  */
	const std::string getName(void) const;
	short int getGrade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &print);

#endif
