/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:28 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	struct Entry
	{
		const char *fName;
		AForm *(*F)(std::string, std::string);
	};

public:
	/*                               EXCEPTIONS                               */
	class FormNotFoundException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	/*                               ORTHODOX CLASS                           */
	Intern(void);
	Intern(const Intern &rhs);
	~Intern(void);
	Intern &operator=(const Intern &rhs);

	/*                               METHODS                                  */
	AForm *makeForm(std::string formName, std::string target);
};

#endif
