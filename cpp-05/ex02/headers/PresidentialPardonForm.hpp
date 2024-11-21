/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:18:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/21 11:46:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	void checkAuth(const short int expect, const short int got);

public:
	/*                               ORTHODOX CLASS                           */
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string _name, const std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	/*                               METHODS                                  */
	void execute(Bureaucrat const &executor);

	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
};

#endif
