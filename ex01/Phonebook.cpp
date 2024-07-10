/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:49:44 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/10 16:59:33 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook(){
	// std::cout << "Phonebook constructor was called" << std::endl;
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
	contact[nb_contact] = newContact;
	nb_contact = (nb_contact + 1) % 7;
	std::cout << "New contact created !" << std::endl << std::endl;
}

void Phonebook::displayAll()
{
	size_t i = 0;

	while (i < 8)
		contact[i++].display();
}