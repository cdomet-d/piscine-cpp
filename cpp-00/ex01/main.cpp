/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:56:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:46:30 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void) {
	Phonebook Phonebook;
	std::string user_input;

	std::cout << COLOR << "Please enter a command: " << END << std::endl
			  << "ADD: add a new contact" << std::endl
			  << "SEARCH: display existing contacts" << std::endl
			  << "EXIT: deletes phonebook and exit the program" << std::endl
			  << std::endl;
	while (1) {
		std::cout << "$ ";
		getline(std::cin, user_input, '\n');
		if (std::cin.eof() == true)
			return (1);
		if (user_input.compare("ADD") == 0)
			Phonebook.addNew();
		else if (user_input.compare("SEARCH") == 0)
			Phonebook.displaySearch();
		else if (user_input.compare("EXIT") == 0)
			break;
		else
			std::cout << PINK << "Unknown command: " << user_input << END
					  << std::endl;
	}
	return (0);
}
