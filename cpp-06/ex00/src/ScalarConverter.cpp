/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:54:51 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/26 17:47:46 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <string>

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
void ScalarConverter::convert(std::string &toConvert)
{
	std::cout << std::fixed << std::showpoint << std::setprecision(1)
			  << "Int: " << static_cast<int>(std::atoi(toConvert.c_str())) << std::endl
			  << "Float: " << static_cast<float>(std::atoi(toConvert.c_str())) << "f" << std::endl
			  << "Double: " << static_cast<double>(std::atoi(toConvert.c_str())) << std::endl
			  << "Char: " << static_cast<char>(std::atoi(toConvert.c_str())) << std::endl;
}
