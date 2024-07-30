/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:58:03 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/30 16:54:45 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.

#include <fstream>
#include <iostream>
#include <string>
#include "Replace.hpp"

int main(int ac, char *av[])
{
	if (ac != 4)
		return (std::cerr << "Invalid argument: please enter a <filename>, <to_find> and <replace>." << std::endl, 1);
	Replace	replace;
	std::string		filename = av[1];
	std::ifstream	infile(filename.c_str());
	std::ofstream	ofile((filename + ".replace").c_str());

	replace.setNeedle(av[2]);
	replace.setRep(av[3]);
	if (!ofile.is_open())
		return (std::cerr << "Error opening file" << std::endl, 1);
	if (!infile.is_open())
		return (std::cerr << "Error opening file" << std::endl, 1);
	replace.setBuffer(infile);
	ofile << replace.retNewStr() << std::endl;
	replace.displayBuffer();
	ofile.close();
	infile.close();
	return (0);
}
