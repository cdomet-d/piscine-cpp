/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:59:10 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/05 14:41:22 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#define DECIMAL 10
#define FEB 2
#define FEB_29 29
#define APRIL 4
#define JUNE 6
#define SEPT 9
#define NOV 11
#define MIN_VALUE 1
#define MAX_MONTH 12
#define MAX_DAYS 31
#define MAX_DAYS_SHORT_MONTH 30
#define MAX_BITCOIN 1000
#define DISPLAY_MARGIN 15
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
	buildMap(',', database_file);
	buildMap('|', input_file);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &comp)
{
	database = comp.database;
	input = comp.input;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */
void BitcoinExchange::getChangeRate()
{
	std::map< std::string, double >::iterator inputIt = input.begin();
	std::map< std::string, double >::iterator dBaseIt = database.begin();

	if (dBaseIt == database.end())
		throw std::runtime_error("Database is empty");
	for (; inputIt != input.end(); ++inputIt) {
		dBaseIt = database.lower_bound(inputIt->first);
		if (inputIt->first != dBaseIt->first || dBaseIt == database.end()) {
			--dBaseIt;
			std::cout << BR << std::left << std::setw(DISPLAY_MARGIN)
					  << "No match ";
			std::cout << "for " << inputIt->first
					  << ", computing with previous known date: "
					  << dBaseIt->first << R << std::endl;
			std::cout << std::setw(DISPLAY_MARGIN) << " ";
			outputBitcoinValue(inputIt, dBaseIt);
		} else {
			std::cout << BG << std::left << std::setw(DISPLAY_MARGIN)
					  << "Match " << R;
			outputBitcoinValue(inputIt, dBaseIt);
		}
	}
}

/* ************************************************************************** */
/*                               INIT                                         */
/* ************************************************************************** */

void BitcoinExchange::buildMap(const char sep, const std::string &filename)
{
	std::cout << "\nExtracting	" + filename << std::endl;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Failed to open file " + filename);

	std::string line;
	std::stringstream current;
	std::string date, val;
	long lineNo = 0;

	while (std::getline(file, line)) {
		if (file.fail())
			throw std::runtime_error("Encountered error while reading " +
									 filename);
		current.clear();
		current.str(line);
		lineNo++;
		try {
			if (std::getline(current, date, sep) &&
				std::getline(current, val)) {
				if (dateIsValid(lineNo, date)) {
					trimDate(date);
					getValidBitValue(sep, val, date, lineNo);
				}
			} else
				pError("Incorrect formatting: expected <YYYY-MM-DD>, "
					   "<separator>, <value>",
					   line, lineNo);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                               PARSING                                      */
/* ************************************************************************** */

void BitcoinExchange::getValidBitValue(char sep, const std::string &val,
									   const std::string &date, long lineNo)
{
	double convertedVal;
	char *rest;

	convertedVal = std::strtod(val.c_str(), &rest);
	if ((sep == '|' && convertedVal > MAX_BITCOIN))
		return static_cast< void >(pError("Too much Bitcoin!", val, lineNo));
	if (!restIsValid(rest, '\0', false, lineNo, val))
		return;
	if (!conversionIsValid(lineNo, val))
		return;
	if (convertedVal < 0)
		return static_cast< void >(
			pError("Bitcoin value can't be negative", val, lineNo));
	if (sep == ',')
		database[date] = convertedVal;
	else if (sep == '|')
		input[date] = convertedVal;
}

bool BitcoinExchange::dateIsValid(long lineNo, const std::string &date)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		return pError("Invalid format", date, lineNo);

	char *rest;
	int year = std::strtol(date.c_str(), &rest, DECIMAL);
	if (!yearIsValid(year, lineNo, rest, date))
		return false;

	int month = std::strtol(rest + 1, &rest, DECIMAL);
	if (!monthIsValid(month, lineNo, rest, date))
		return false;

	int day = std::strtol(rest + 1, &rest, DECIMAL);
	if (!dayIsValid(year, month, day, lineNo, rest, date))
		return false;
	return true;
}

bool BitcoinExchange::yearIsValid(int year, long lineNo, const char *rest,
								  const std::string &date)
{
	if (!restIsValid(rest, '-', false, lineNo, date))
		return false;
	if (!conversionIsValid(lineNo, date))
		return false;
	if (year < 0)
		return pError("Year cannot be negative", date, lineNo);
	return true;
}

bool BitcoinExchange::monthIsValid(int month, long lineNo, const char *rest,
								   const std::string &date)
{
	if (!restIsValid(rest, '-', false, lineNo, date))
		return false;
	if (!conversionIsValid(lineNo, date))
		return false;
	if (month < MIN_VALUE || month > MAX_MONTH)
		return pError("Month is out of range (01 - 12)", date, lineNo);
	return true;
}

bool BitcoinExchange::dayIsValid(int year, int month, int day, long lineNo,
								 const char *rest, const std::string &date)
{
	if (!restIsValid(rest, '\0', true, lineNo, date))
		return false;
	if (!conversionIsValid(lineNo, date))
		return false;
	if (day < MIN_VALUE || day > MAX_DAYS)
		return pError("Day is out of range (01 - 31)", date, lineNo);
	if (month == FEB && day == FEB_29)
		if (!isLeapYear(year, lineNo, date))
			return false;
	if ((month == APRIL || month == JUNE || month == SEPT || month == NOV) &&
		day > MAX_DAYS_SHORT_MONTH)
		return pError("No such day in that month", date, lineNo);
	return true;
}

/* ************************************************************************** */
/*                               HELPERS                                      */
/* ************************************************************************** */

void BitcoinExchange::trimDate(std::string &date)
{
	size_t i = date.find_first_of(" \f\n\r\t\v");

	while (i != std::string::npos && iswspace(date[i])) {
		date.erase(date.begin() + i);
		i++;
		i--;
	}
}

bool BitcoinExchange::restIsValid(const char *rest, char expectedChar,
								  bool acceptWSpace, long lineNo,
								  const std::string &line)
{
	if (*rest != expectedChar) {
		if (acceptWSpace && iswspace(*rest))
			return true;
		return pError("Unexpected characters in date", line, lineNo);
	}
	return true;
}

bool BitcoinExchange::conversionIsValid(long lineNo, const std::string &date)
{
	if (errno == ERANGE) {
		errno = 0;
		return pError("Too large a number", date, lineNo);
	}
	errno = 0;
	return true;
}

bool BitcoinExchange::isLeapYear(int year, long lineNo, const std::string &date)
{
	/* leap years are divisible by 4 unless they are also divisible by 100, 
	with the exception that if the year is also divisible by 400, it is also a leap year.*/
	if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return pError("Not a leap year", date, lineNo);
	return true;
}

/* ************************************************************************** */
/*                               DISPLAY                                      */
/* ************************************************************************** */

void BitcoinExchange::print()
{
	std::cout << std::endl << "Database :" << std::endl;
	for (std::map< std::string, double >::iterator it = database.begin();
		 it != database.end(); ++it)
		std::cout << it->first << ":	" << it->second << std::endl;

	std::cout << std::endl << "Input :" << std::endl;
	for (std::map< std::string, double >::iterator it = input.begin();
		 it != input.end(); ++it)
		std::cout << it->first << ":	" << it->second << std::endl;
	std::cout << std::endl;
}

void BitcoinExchange::outputBitcoinValue(
	std::map< std::string, double >::iterator inputIt,
	std::map< std::string, double >::iterator dBaseIt)
{
	std::cout << "On " + inputIt->first + ", the value of ";
	std::cout << std::setw(5) << inputIt->second
			  << "	bitcoin(s) was " << std::right << std::setw(DISPLAY_MARGIN)
			  << std::fixed << std::setprecision(2)
			  << inputIt->second * dBaseIt->second << "$" << std::endl;
}

bool BitcoinExchange::pError(const std::string &err, const std::string &errLine,
							 size_t lineNo)
{
	std::cout << BR << "On line: " << R << lineNo << ": " + errLine + ": " + err
			  << std::endl;
	return false;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */