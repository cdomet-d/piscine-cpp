/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:58:03 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:45 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char *av[]) {
	if (ac != 4)
		return (std::cout << PINK
						  << "Invalid argument: please enter a <filename>, \
		<to_find> and <replace>."
						  << END << std::endl,
				1);

	Replace replace;

	std::string filename = av[1];
	replace.setRep(av[3]);
	replace.setNeedle(av[2]);
	if (!replace.checkNeedle())
		return (std::cout << PINK << "Error: empty search" << END << std::endl,
				1);

	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
		return (std::cout << PINK << "Error: opening file" << END << std::endl,
				1);

	std::ofstream ofile((filename + ".replace").c_str());
	if (!ofile.is_open())
		return (std::cout << PINK << "Error: opening file" << END << std::endl,
				1);

	replace.setBuffer(infile);
	infile.close();
	ofile << replace.retNewStr() << std::endl;
	ofile.close();
	return (0);
}
