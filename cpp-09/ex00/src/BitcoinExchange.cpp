/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:10 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/19 16:49:34 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

#define DECIMAL 10
#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string &database_file,
								 const std::string &input_file)
{

	std::cout << database_file + "		" + input_file << std::endl;
	this->buildMap(',', database_file);
	this->buildMap('|', input_file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &comp)
{
	this->database = comp.database;
	this->input = comp.input;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void BitcoinExchange::buildMap(const char sep, const std::string &filename)
{
	std::cout << "\nExtracting	" + filename << std::endl << std::endl;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file " + filename);

	std::string line;
	std::stringstream current;
	std::string key, val;
	long line_count = 0;

	while (std::getline(file, line)) {
		if (file.fail())
			throw std::runtime_error("Encountered error while reading " +
									 filename);
		current.clear();
		current.str(line);
		line_count++;
		try {
			if (std::getline(current, key, sep) && std::getline(current, val)) {
				if (this->dateIsValid(key, line_count))
					this->getValidBitValue(sep, val, key, line_count);
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}
void BitcoinExchange::getValidBitValue(char sep, const std::string &val,
									   const std::string &key, long line_count)
{
	double convertedVal;
	char *endptr;

	convertedVal = std::strtod(val.c_str(), &endptr);
	if (*endptr) {
		this->printError("Unexpected characters in bitcoin value", val,
						 line_count);
		return;
	}
	if (errno == ERANGE || convertedVal > 1000) {
		this->printError("Too large a number", val, line_count);
		return;
	}
	if (convertedVal < 0) {
		this->printError("Bitcoin value can't be negative", val, line_count);
		return;
	}
	if (sep == ',')
		database[key] = convertedVal;
	else if (sep == '|')
		input[key] = convertedVal;
}

bool BitcoinExchange::dateIsValid(const std::string &date, long line_count)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		return this->printError("Invalid format", date, line_count);

	char *remainder;
	int year = std::strtol(date.c_str(), &remainder, DECIMAL);
	if (!this->yearIsValid(remainder, date, year, line_count))
		return false;

	int month = std::strtol(remainder + 1, &remainder, DECIMAL);
	if (!this->monthIsValid(remainder, date, month, line_count))
		return false;

	int day = std::strtol(remainder + 1, &remainder, DECIMAL);
	if (!this->dayIsValid(remainder, date, year, month, day, line_count))
		return false;
	return true;
}

bool BitcoinExchange::yearIsValid(char *remainder, const std::string &date,
								  int year, long line_count)
{
	if (*remainder != '-')
		return this->printError("Unexpected characters in date", date,
								line_count);
	if (errno == ERANGE)
		return this->printError("Too large a numnber", date, line_count);
	if (year < 0)
		return this->printError("Number cannot be negative", date, line_count);
	return true;
}

bool BitcoinExchange::monthIsValid(char *remainder, const std::string &date,
								   int month, long line_count)
{
	if (*remainder != '-')
		return this->printError("Unexpected characters in date", date,
								line_count);
	if (errno == ERANGE)
		return this->printError("Too large a numnber", date, line_count);
	if (month < 1 || month > 12)
		return this->printError("Month is out of range (01 - 12)", date,
								line_count);
	return true;
}
bool BitcoinExchange::dayIsValid(char *remainder, const std::string &date,
								 int year, int month, int day, long line_count)
{
	if (*remainder && *remainder != ' ')
		return this->printError("Unexpected characters in date", date,
								line_count);
	if (errno == ERANGE)
		return this->printError("Too large a number", date, line_count);
	if (day < 1 || day > 31)
		return this->printError("Day is out of range (01 - 31)", date,
								line_count);
	if (month == 2 && day == 29)
		if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return this->printError("Not a leap year", date, line_count);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return this->printError("No such day in that month", date, line_count);
	return true;
}

void BitcoinExchange::print()
{
	std::cout << std::endl << "Database :" << std::endl;
	for (std::map< std::string, double >::iterator it = database.begin();
		 it != database.end(); ++it)
		std::cout << it->first << " :	" << it->second << std::endl;

	std::cout << std::endl << "Input :" << std::endl;
	for (std::map< std::string, double >::iterator it = input.begin();
		 it != input.end(); ++it)
		std::cout << it->first << " :	" << it->second << std::endl;
}

bool BitcoinExchange::printError(const std::string &err, std::string error_line,
								 long line_count)
{
	std::cout << "On line: " << line_count << ": " + error_line + ": " + err
			  << std::endl;
	return false;
}
/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */