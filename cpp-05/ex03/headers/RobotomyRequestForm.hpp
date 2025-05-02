/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:50:08 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  private:
	void checkAuth(const short int expect, const short int got);
	bool halfChance(void);

  public:
	/*                               ORTHODOX CLASS                           */
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string _name, const std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	/*                               METHODS                                  */
	void execute(Bureaucrat const &executor);
};

#endif
