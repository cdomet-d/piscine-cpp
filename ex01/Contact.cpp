/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:57:32 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/16 17:00:35 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static std::string	convertStr(std::string str)
{
	if (str.length() > 10)
		return(str.substr(0, 9).replace(9, 1, "."));
	return (str);
}

Contact::Contact(void) {
	index = 0;
}

Contact::Contact(std::string newContact[5], size_t i)
{
	index = i + 1;
	firstName = newContact[0];
	lastName = newContact[1];
	nickName = newContact[2];
	phoneNumber = newContact[3];
	darkestSecret = newContact[4];
}

void Contact::displayPhonebook(void)
{
	if (firstName.empty() == false)
	{
		std::cout << std::setw(10) << std::right << index << " | "
			<< std::setw(10) << convertStr(firstName) << " | "
			<< std::setw(10) << convertStr(lastName) <<  " | "
			<< std::setw(10) << convertStr(nickName) << " | "
			<< std::endl;
	}
}

void Contact::displayContact(void)
{
	if (firstName.empty() == false)
	{
		std::cout << std::endl
			<< "First name: " << firstName << std::endl
			<< "Last name: " << lastName << std::endl
			<< "Nickname: " << nickName << std::endl
			<< "Phone number: " << phoneNumber << std::endl
			<< "Darkest secret: " << darkestSecret << std::endl
			<< std::endl;
	}
}
