/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:44:16 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/16 16:28:21 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>

#define DECIMAL 10
#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

Database::Database(void) {}

Database::Database(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file " + filename);

	char *endptr;
	std::string line;
	std::stringstream current;
	std::string key, val;
	double convertedVal;

	while (std::getline(file, line)) {
		if (file.fail())
			throw std::runtime_error("Encountered error while reading " +
									 filename);
		current.clear();
		current.str(line);
		try {
			if (std::getline(current, key, ',') && std::getline(current, val)) {
				if (this->dateIsValid(key)) {
					convertedVal = std::strtod(val.c_str(), &endptr);
					if (!endptr[0])
						database[key] = convertedVal;
					else
						std::cout << "ignored value: " + line << std::endl;
				} else
					std::cout << "ignored value: " + line << std::endl;
			} else
				std::cout << "ignored value: " + line << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
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
	(void)comp;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void Database::print()
{
	std::cout << std::endl << "Database :" << std::endl;
	for (std::map< std::string, double >::iterator it = database.begin();
		 it != database.end(); ++it)
		std::cout << it->first << " |	" << it->second << std::endl;
}

bool Database::dateIsValid(const std::string &date)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		return false;

	char *remainder;
	int year = std::strtol(date.c_str(), &remainder, DECIMAL);
	if (year < 1 || *remainder != '-')
		return false;

	int month = std::strtol(remainder + 1, &remainder, DECIMAL);
	if (month < 1 || month > 12 || *remainder != '-')
		return false;

	int day = std::strtol(remainder + 1, &remainder, DECIMAL);
	if (day < 1 || day > 31 || *remainder)
		return false;
	if (month == 2 && day == 29)
	{
		if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */