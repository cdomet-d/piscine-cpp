/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:24:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/25 11:53:08 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

int	main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout	<< std:: left
				<< std::setw(35) << "Memory address of the string" << ": " << &brain << std::endl
				<< std::setw(35) << "Memory address of the pointer" << ": " << stringPTR << std::endl
				<< std::setw(35) << "Memory address of the reference" << ": " << &stringREF << std::endl
				<< std::endl
				<< std::setw(35) << "Value of the string" << ": " << brain << std::endl
				<< std::setw(35) << "Value of the pointer" << ": " << *stringPTR << std::endl
				<< std::setw(35) << "Value of the reference" << ": " << stringREF << std::endl;
}
