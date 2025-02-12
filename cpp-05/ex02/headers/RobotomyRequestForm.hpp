/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:19:00 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
private:
	bool halfChance(void);
	void checkAuth(const short int expect, const short int got);

public:
	/*                               ORTHODOX CLASS                           */
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	/*                               METHODS                                  */
	void execute(Bureaucrat const &executor);
};

#endif
