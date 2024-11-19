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

class AForm
{
private:
	const std::string name;
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

	/*                               ORTHODOX CLASS                           */
	AForm(void);
	AForm(const std::string _name, const short int _signGrade, const short _execGrade);
	AForm(const AForm &copy);
	~AForm(void);
	AForm &operator=(const AForm &copy);

	/*                               METHODS                                  */
	void	beSigned(const Bureaucrat signer);

	/*                               GETTERS                                  */
	const std::string getName(void) const;
	short int getSignGrade(void) const;
	short int getExecGrade(void) const;
	bool getSignedStatus(void) const;

	/*                               SETTERS                                  */
};

std::ostream &operator<<(std::ostream &os, const AForm &print);

#endif
