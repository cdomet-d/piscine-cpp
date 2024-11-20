/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/20 17:28:40 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

void testBureaucrats(void);
void testFormSignature(void);
void testForms(void);

int main(void)
{
	try {
		Bureaucrat Kevin("Kevin", 10);
		PresidentialPardonForm pardon("Pardon", "Johnny");
		Kevin.signForm(pardon);
		std::cout << pardon << std::endl;
		pardon.execute(Kevin);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
		
	return (0);
}
