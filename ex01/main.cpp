/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:56:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/16 17:05:15 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	Phonebook 	Phonebook;
	std::string	user_input;

	std::cout << std::endl  <<"Please enter a command" << std::endl << std::endl
		 << "ADD: add a new contact" << std::endl
		 << "SEARCH: display existing contacts" << std::endl
		 << "EXIT: deletes phonebook and exit the program" << std::endl
		 << std::endl;
	while (1)
	{
		getline(std::cin, user_input, '\n');
		if (user_input.compare("ADD") == 0)
			Phonebook.addNew();
		else if (user_input.compare("SEARCH") == 0)
			Phonebook.displaySearch();
		else if (user_input.compare("EXIT") == 0)
			break ;
	}
	return (0);
}
