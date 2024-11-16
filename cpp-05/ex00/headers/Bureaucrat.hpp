/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:14:32 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/16 20:36:16 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
private:
	const std::string name;
	short int grade;

public:
	/*                               ORTHODOX CLASS                           */
	Bureaucrat(void);
	Bureaucrat(const std::string _name, short int _grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);
	Bureaucrat &operator=(const Bureaucrat &copy);

	/*                               METHODS                                  */

	/*                           OPERATOR OVERLOAD                            */
	Bureaucrat &operator++(void);
	Bureaucrat operator++(int n);
	Bureaucrat &operator--(void);
	Bureaucrat operator--(int n);

	/*                               GETTERS                                  */
	const std::string getName(void) const;
	short int getGrade(void) const;

	/*                               SETTERS                                  */
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &print);

#endif
