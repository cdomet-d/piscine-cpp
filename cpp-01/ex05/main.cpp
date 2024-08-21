/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:24:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/21 11:08:57 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main(int ac, char *argv[])
{	
	Harl test;

	if (ac < 2)
		return (std::cerr << "ERROR: No complain level provided" << std::endl, 1);
	for (size_t i = 1; argv[i]; i++)
	{
		try {
			test.complain(argv[i]);
		}
		catch (const std::exception& e)	{
			std::cerr << "ERROR: "  << argv[i] << ": " << e.what() << std::endl;
		}
	}
}