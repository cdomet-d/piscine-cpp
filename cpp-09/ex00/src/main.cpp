/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:04:22 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/14 17:32:53 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Database.hpp"

int main(int ac, char *av[])
{
	(void)av;
	if (ac != 2) {
		std::cout << "Expected an argument\nUsage: <./btc <input.txt>"
				  << std::endl;
		return (1);
	}
	Database test("database/data.csv");

	test.print();
}