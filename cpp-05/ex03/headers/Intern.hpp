/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:32:28 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/22 16:54:51 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
public:
	/*                               ORTHODOX CLASS                           */
	Intern(void);
	Intern(const Intern &copy);
	~Intern(void);
	Intern &operator=(const Intern &copy);

	/*                               METHODS                                  */
	AForm &makeForm(std::string formName, std::string target);
};

#endif
