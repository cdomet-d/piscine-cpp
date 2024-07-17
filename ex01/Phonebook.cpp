/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:49:44 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/17 12:03:19 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>


Phonebook::Phonebook(){
	nb_contact = 0;
}

void Phonebook::addNew()
{
	std::string newContact[5];
	size_t	i = 0;
	
	std::cout << "Creating new contact" << std::endl;
	while (i < 5)
	{
		if (i == 0)
			std::cout << "First Name: ";
		else if (i == 1)
			std::cout << "Last Name: ";
		else if (i == 2)
			std::cout << "Nickname: ";
		else if (i == 3)
			std::cout << "Phone Number: ";
		else if (i == 4)
			std::cout << "Darkest Secret: ";
		getline(std::cin, newContact[i], '\n');
		if (newContact[i].empty() == false)
			i++;
	}
	contact[nb_contact] = Contact(newContact, nb_contact);
	nb_contact = (nb_contact + 1) % 8;
	std::cout << std::endl << "New contact created ! <3" << std::endl << std::endl;
}

static void	displayHeader(void)
{
	std::cout << std::endl;
	std::cout << std::setfill('.') << std::setw(10) << "Index" << " | "
	<< std::setw(10) << "First name" << " | "
	<< std::setw(10) << "Last name" << " | "
	<< std::setw(10) << "Nickname" << " | "
	<< std::endl;
}

void Phonebook::displayIndex()
{
	std::string		index;
	size_t			input;
	bool			isValid = false;

	if (nb_contact == 0)
	{
		std::cout << "You do not have any contacts... try ADD" << std::endl;
		return;
	}
	while (!isValid)
	{
		std::cout << "Enter the index of the contact your wish to see [1 - 8]" << std::endl;
		std::cout << "$ ";
		getline(std::cin, index, '\n');
		if (index.length() > 1)
			std::cout << "Invalid input" << std::endl;
		else
		{
			input = index[0] - '0';
			if ((input >= 1 && input <= 8) && input <= nb_contact)
			{
				displaySingle(input - 1);
				isValid = true;
			}
			else
				std::cout << "Invalid input" << std::endl;
		}
	}
}

void Phonebook::displaySingle(size_t i)
{
	contact[i].displayContact();
}

void Phonebook::displaySearch()
{
	size_t i = 0;
	
	displayHeader();
	while (i < 8)
		contact[i++].displayPhonebook();
	std::cout << std::endl;
	displayIndex();
}
