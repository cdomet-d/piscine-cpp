/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:34:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/20 16:35:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string _name, const std::string _target, const short int _signGrade, const short _execGrade);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

	/*                               METHODS                                  */
	
	/*                               GETTERS                                  */
	
	/*                               SETTERS                                  */
};

#endif