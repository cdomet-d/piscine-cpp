/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:58:03 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/29 11:47:13 by cdomet-d         ###   ########lyon.fr   */
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
	
	std::string	filename = av[1];
	std::string	to_find = av[2];
	std::string	to_replace = av[3];
	
	std::cout	<< filename << " | "
				<< to_find << " | "
				<< to_replace
				<< std::endl;
	// std::ifstream	ifile;
	// ifile.open(filename);
	std::string newfile = filename.append(".replace");
	std::ofstream	ofile;
	ofile.open(newfile);
	ofile << "hello this is a test" << std::endl;
	ofile.close();
	

}
