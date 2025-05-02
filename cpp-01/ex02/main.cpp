/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:24:24 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:23 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>

int main(void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << std::left << std::setw(35) << "Memory address of the string"
			  << ": " << &brain << std::endl
			  << std::setw(35) << "Memory address of the pointer" << ": "
			  << stringPTR << std::endl
			  << std::setw(35) << "Memory address of the reference" << ": "
			  << &stringREF << std::endl
			  << std::endl
			  << std::setw(35) << "Value of the string" << ": " << brain
			  << std::endl
			  << std::setw(35) << "Value of the pointer" << ": " << *stringPTR
			  << std::endl
			  << std::setw(35) << "Value of the reference" << ": " << stringREF
			  << std::endl;
}
