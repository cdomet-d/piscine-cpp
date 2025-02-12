/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:38:33 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/19 14:48:49 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

#define PRESIDENT_EXEC_GRADE 5
#define ROBOTOMY_EXEC_GRADE 45
#define SHRUBBERY_EXEC_GRADE 137

class AForm
{
private:
	const std::string name;
	const std::string target;
	const short int signGrade;
	const short int execGrade;
	bool isSigned;

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
	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	/*                               ORTHODOX CLASS                           */
	AForm(void);
	AForm(const std::string _name, const std::string _target, const short int _signGrade, const short _execGrade);
	AForm(const AForm &rhs);
	virtual ~AForm(void);
	AForm &operator=(const AForm &rhs);

	/*                               METHODS                                  */
	void beSigned(const Bureaucrat signer);
	virtual void checkAuth(const short int expect, const short int got) = 0;
	virtual void execute(Bureaucrat const &executor) = 0;

	/*                               GETTERS                                  */
	bool getSignedStatus(void) const;
	const std::string getName(void) const;
	const std::string getTarget(void) const;
	short int getExecGrade(void) const;
	short int getSignGrade(void) const;

	/*                               SETTERS                                  */
};

std::ostream &operator<<(std::ostream &os, const AForm &print);

#endif
