/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:49:44 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/11 16:53:34 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

static void	displayHeader(void)
{
	std::cout << std::endl;
	std::cout << std::setfill('.') << std::setw(10) << "Index" << " | "
	<< std::setw(10) << "First name" << " | "
	<< std::setw(10) << "Last name" << " | "
	<< std::setw(10) << "Nickname" << " | "
	<< std::endl;
}

static void	displayIndex()
{
	size_t	i;

	std::cin >> i;
	if (isdigit())
}

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
	nb_contact = (nb_contact + 1) % 7;
	std::cout << std::endl << "New contact created ! <3" << std::endl << std::endl;
}

void Phonebook::displayAll()
{
	size_t i = 0;

	while (i < 8)
		contact[i++].displayContact();
}

void Phonebook::displaySearch()
{
	size_t i = 0;
	
	displayAll();
	while (i < 8)
		contact[i++].displayPhonebook();
	std::cout << std::endl;
}
