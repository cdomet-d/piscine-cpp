/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:54:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/27 13:59:22 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "default deconstructor called " << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &comp)
{
	(void)comp;
	return (*this);
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

void ScalarConverter::printChar(int c)
{
	if (c >= 32 && c <= 127)
		std::cout << "Char: |" << static_cast<char>(c) << "|" << std::endl;
	else
		std::cout << "Char: Out of printable range" << std::endl;
}

bool ScalarConverter::isValid(std::string str)
{
	if (ScalarConverter::isChar(str))
		return true;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (!isdigit(*it))
		{
			if (it == str.begin() && *it == '-')
				continue;
			return false;
		}
	}
	return true;
}

bool ScalarConverter::isChar(std::string str)
{
	if (str.length() > 1)
		return (false);
	if (str[0] >= '0' && str[0] <= '9')
		return (false);
	else
		return (true);
}

void ScalarConverter::convert(std::string &toConvert)
{
	if (!ScalarConverter::isValid(toConvert))
	{
		std::cout << "Is invalid charset " << std::endl;
		return;
	}
	if (ScalarConverter::isChar(toConvert))
	{
		char c = toConvert[0];
		std::cout << std::fixed << std::showpoint << std::setprecision(1)
				  << "Int: " << static_cast<int>(c) << std::endl
				  << "Float: " << static_cast<float>(c) << "f" << std::endl
				  << "Double: " << static_cast<double>(c) << std::endl
				  << "Char: " << static_cast<char>(c) << std::endl;
		return;
	}
	long c = std::atoll(toConvert.c_str());
	
	std::cout << std::numeric_limits<long long>::max() << std::endl;
	std::cout << c << std::endl;

	std::cout << std::fixed << std::showpoint << std::setprecision(1)
			  << "Int: " << ((c >= std::numeric_limits<int>::min() && c <= std::numeric_limits<int>::max()) ? std::to_string(static_cast<int>(c)) : "Impossible") << std::endl
			  << "Double: " << ((c >= std::numeric_limits<double>::min() && c <= std::numeric_limits<double>::max()) ? std::to_string(static_cast<double>(c)) : "Impossible") << std::endl 
			  << "Float: " << ((c >= std::numeric_limits<int>::min() && c <= std::numeric_limits<int>::max()) ? std::to_string(static_cast<float>(c)) : "Impossible") << std::endl 
			  << "Char: " << ((c >= std::numeric_limits<char>::min() && c <= std::numeric_limits<char>::max()) ? std::to_string(static_cast<char>(c)) : "Impossible") << std::endl 
			  << std::endl;
}
