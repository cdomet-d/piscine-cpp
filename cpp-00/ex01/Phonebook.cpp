/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:49:44 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:46:33 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iomanip>
#include <iostream>

Phonebook::Phonebook() {
	nb_contact = -1;
}

void Phonebook::addNew() {
	std::string newContact[5];
	size_t i = 0;

	std::cout << COLOR << "Creating new contact..." << END << std::endl;
	while (i < 5) {
		if (i == 0)
			std::cout << "	First Name: ";
		else if (i == 1)
			std::cout << "	Last Name: ";
		else if (i == 2)
			std::cout << "	Nickname: ";
		else if (i == 3)
			std::cout << "	Phone Number: ";
		else if (i == 4)
			std::cout << "	Darkest Secret: ";
		getline(std::cin, newContact[i], '\n');
		if (std::cin.eof() == true)
			return;
		if (newContact[i].empty() == false)
			i++;
	}
	if (nb_contact == -1)
		nb_contact = 0;
	contact[nb_contact] = Contact(newContact, nb_contact);
	nb_contact = (nb_contact + 1) % 8;
	std::cout << std::endl
			  << COLOR << "New contact added !" << END << std::endl
			  << std::endl;
}

static void displayHeader(void) {
	std::cout << std::endl
			  << std::setfill('.') << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First name" << " | " << std::setw(10)
			  << "Last name" << " | " << std::setw(10) << "Nickname" << " | "
			  << std::endl;
}

void Phonebook::displayIndex() {
	std::string index;
	size_t input;
	bool isValid = false;

	if (nb_contact == -1) {
		std::cout << COLOR << "You do not have any contacts... try " << END
				  << PINK << "ADD" << END << std::endl;
		return;
	}
	while (!isValid) {
		std::cout << COLOR
				  << "Enter the index of the contact your wish to see [1 - 8]"
				  << END << std::endl
				  << "$ ";
		getline(std::cin, index, '\n');
		if (std::cin.eof() == true)
			return;
		if (index.length() > 1)
			std::cout << PINK << "Invalid input" << END << std::endl;
		else {
			input = index[0] - '0';
			if ((input >= 1 && input <= 8)) {
				displaySingle(input - 1);
				isValid = true;
			} else
				std::cout << PINK << "Invalid input" << END << std::endl;
		}
	}
}

void Phonebook::displaySingle(size_t i) {
	contact[i].displayContact();
}

void Phonebook::displaySearch() {
	size_t i = 0;

	displayHeader();
	while (i < 8)
		contact[i++].displayPhonebook();
	std::cout << std::endl;
	displayIndex();
}
