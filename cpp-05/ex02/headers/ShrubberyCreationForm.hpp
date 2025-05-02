/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:42 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  private:
	void checkAuth(const short int expect, const short int got);

  public:
	/*                               ORTHODOX CLASS                           */
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	/*                               METHODS                                  */
	void execute(Bureaucrat const &executor);
};

#endif
