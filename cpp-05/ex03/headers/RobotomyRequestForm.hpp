/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/25 10:32:17 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
private:
	void checkAuth(const short int expect, const short int got);
	bool halfChance(void);

public:
	/*                               ORTHODOX CLASS                           */
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string _name, const std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

	/*                               METHODS                                  */
	void execute(Bureaucrat const &executor);
};

#endif
