/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:38:33 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/18 15:40:11 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Form
{
private:
	const std::string name;
	const short int signGrade;
	const short int execGrade;
	bool isSigned;

public:
	/*                               EXCEPTIONS                               */
	class GradeTooHigh : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLow : public std::exception
	{
	public:
		const char *what() const throw();
	};

	/*                               ORTHODOX CLASS                           */
	Form(void);
	Form(const std::string _name, const short int _signGrade, const short _execGrade);
	Form(const Form &copy);
	~Form(void);
	Form &operator=(const Form &copy);

	/*                               METHODS                                  */

	/*                               GETTERS                                  */
	const std::string getName(void) const;
	const short int getSignGrade(void) const;
	const short int getExecGrade(void) const;
	const bool getSignedStatus(void) const;

	/*                               SETTERS                                  */
};

std::ostream &operator<<(std::ofstream &os, const Form &print);
#endif
