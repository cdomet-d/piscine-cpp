/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:04:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/03 16:56:54 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cout << "Expected an argument\nUsage: ./btc <input.txt> "
					 "(optionnal) <database.txt>"
				  << std::endl;
		return (1);
	}
	std::string input_file = av[1];
	std::string database_file;

	if (ac == 3)
		database_file = av[2];
	else
		database_file = "database/data.csv";
	{
		try {
			BitcoinExchange test(database_file, input_file);
			test.getChangeRate();
		} catch (std::exception &e) {
			std::cout << "ERROR :	" << e.what() << std::endl;
			return 1;
		}
	}
}