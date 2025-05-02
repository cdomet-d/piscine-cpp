/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:18:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:38 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
	void checkAuth(const short int expect, const short int got);

  public:
	/*                               ORTHODOX CLASS                           */
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	/*                               METHODS                                  */
	void execute(Bureaucrat const &executor);
};

#endif
