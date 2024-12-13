/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:54:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/13 14:41:08 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &comp)
{
	(void)comp;
	return (*this);
}

/* ************************************************************************** */
/*                               DISPLAY                                      */
/* ************************************************************************** */

void ScalarConverter::printChar(double c)
{
	if (c >= 32 && c <= 127)
		std::cout << std::fixed << std::showpoint << std::setprecision(1)
				  << "Char: '" << static_cast< char >(c) << "'" << std::endl;
	else
		std::cout << "Char: not displayable" << std::endl;
}

void ScalarConverter::printInt(double c)
{
	if (c >= std::numeric_limits< int >::min() &&
		c <= std::numeric_limits< int >::max())
		std::cout << std::fixed << std::showpoint << std::setprecision(1)
				  << "Int: " << static_cast< int >(c) << std::endl;
	else
		std::cout << "Int: impossible conversion" << std::endl;
}

void ScalarConverter::printFloat(double c)
{
	if ((c >= -(std::numeric_limits< float >::max()) &&
		 c <= std::numeric_limits< float >::max()) ||
		std::numeric_limits< float >::signaling_NaN())
		std::cout << std::fixed << std::showpoint << std::setprecision(1)
				  << "Float: " << static_cast< float >(c) << "f" << std::endl;
	else
		std::cout << "Float: impossible conversion" << std::endl;
}

void ScalarConverter::printDouble(double c)
{
	if ((c >= -(std::numeric_limits< double >::max()) &&
		 c <= std::numeric_limits< double >::max()) ||
		std::numeric_limits< double >::signaling_NaN())
		std::cout << std::fixed << std::showpoint << std::setprecision(1)
				  << "Double: " << static_cast< double >(c) << std::endl;
	else
		std::cout << "Double: impossible conversion" << std::endl;
}

void ScalarConverter::printCharInput(const std::string &str)
{
	char c = str[0];
	std::cout << std::fixed << std::showpoint << std::setprecision(1)
			  << "Int: " << static_cast< int >(c) << std::endl
			  << "Float: " << static_cast< float >(c) << "f" << std::endl
			  << "Double: " << static_cast< double >(c) << std::endl
			  << "Char: " << static_cast< char >(c) << std::endl;
}

/* ************************************************************************** */
/*                               PARSING                                      */
/* ************************************************************************** */
bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() > 1)
		return (false);
	if (str[0] >= '0' && str[0] <= '9')
		return (false);
	else
		return (true);
}

bool ScalarConverter::isValid(const std::string &str)
{
	return str == "f" || str.empty();
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void ScalarConverter::convert(std::string &toConvert)
{
	char *endptr;

	if (ScalarConverter::isChar(toConvert))
		return ScalarConverter::printCharInput(toConvert);
	double c = std::strtod(toConvert.c_str(), &endptr);
	if (errno == ERANGE) {
		std::cout << "Out of range" << std::endl;
		return;
	}
	if (!ScalarConverter::isValid(endptr)) {
		std::cout << "Is invalid charset " << std::endl;
		return;
	}
	ScalarConverter::printChar(c);
	ScalarConverter::printDouble(c);
	ScalarConverter::printFloat(c);
	ScalarConverter::printInt(c);
}
