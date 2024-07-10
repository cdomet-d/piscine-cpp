/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:57:32 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/10 17:05:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
	// std::cout << "Contact constructor was called" << std::endl;
}

Contact::Contact(std::string newContact[5])
{
	firstName = newContact[0];
	lastName = newContact[1];
	nickName = newContact[2];
	phoneNumber = newContact[3];
	darkestSecret = newContact[4];
}

void Contact::display(void) 
{
	if (firstName.empty() == false)
	{
		std::cout << std::endl;
		std::cout << "First name: " << firstName << std::endl;
		std::cout << "Last name:" << lastName << std::endl;
		std::cout << "Nickname: " << nickName << std::endl;
		std::cout << "Phone number: " << phoneNumber << std::endl;
		std::cout << "Darkest secret: " << darkestSecret << std::endl;
		std::cout << std::endl;
	}
}

void Contact::displayf(void)
{
	if (firstName.empty() == false)
	{
		std::cout << std::endl;
		std::cout << "First name: " << firstName << std::endl;
		std::cout << "Last name:" << lastName << std::endl;
		std::cout << "Nickname: " << nickName << std::endl;
		std::cout << "Phone number: " << phoneNumber << std::endl;
		std::cout << "Darkest secret: " << darkestSecret << std::endl;
		std::cout << std::endl;
	}
}