/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:04:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/19 16:50:21 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Expected an argument\nUsage: <./btc <input.txt>"
				  << std::endl;
		return (1);
	}
	std::string input_file = av[1];
	try {
		BitcoinExchange test("database/baddta.csv", input_file);
		test.print();
	} catch (std::exception &e) {
		std::cout << "ERROR :	" << e.what() << std::endl;
		return 1;
	}
}