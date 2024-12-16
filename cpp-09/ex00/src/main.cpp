/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:04:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/16 16:07:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <locale>

#include "Database.hpp"

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Expected an argument\nUsage: <./btc <input.txt>"
				  << std::endl;
		return (1);
	}
	std::string dBaseFile = av[1];
	try {
		Database test("database/oob-days.csv");
		test.print();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}