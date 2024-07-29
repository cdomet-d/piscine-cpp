/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:58:03 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/29 15:28:41 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.

#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	if (ac != 4)
		return (std::cerr << "Invalid argument: please enter a <filename>, <to_find> and <replace>." << std::endl, 1);
	
	std::string		filename = av[1];
	std::string		to_find = av[2];
	std::string		to_replace = av[3];
	std::string		buffer;
	std::ifstream	ifile(filename.c_str());
	std::ofstream	ofile((filename + ".replace").c_str());
	
	if (!ofile.is_open())
		return (std::cerr << "Error opening file" << std::endl, 1);
	if (!ifile.is_open())
		return (std::cerr << "Error opening file" << std::endl, 1);
	while (getline(ifile, buffer))
	{
		std::cout << buffer << std::endl;
		int	i = buffer.find(to_find, to_find.length());
		if (i > 0)
			std::cout	<< buffer[i] << std::endl;
		ofile << buffer << std::endl;
	}
	ofile.close();
	ifile.close();
	return (0);
}
		