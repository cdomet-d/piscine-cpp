/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:44:16 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/14 17:33:25 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"
#include <fstream>
#include <sstream>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Database::Database(void) {}

Database::Database(std::string filename)
{
	std::ifstream file(filename.c_str());

	try {
		char *endptr;
		std::string line;
		std::stringstream current;
		std::string key, val;

		while (std::getline(file, line)) {
			current.clear();
			current.str(line);
			if (std::getline(current, key, ',') && std::getline(current, val))
				database[key] = std::strtoll(val.c_str(), &endptr, 10);
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

Database::Database(const Database &copy)
{
	*this = copy;
}

Database::~Database(void) {}

Database &Database::operator=(const Database &comp)
{
	// copy instructions
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void Database::print()
{

	for (std::map< std::string, int >::iterator it = database.begin();
		 it != database.end(); ++it)
		std::cout << it->first << ":" << it->second << std::endl;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

std::map< std::string, int >::iterator Database::getDBBegin()
{
	return this->database.begin();
}

std::map< std::string, int >::iterator Database::getDBEnd()
{
	return this->database.end();
}
/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */