/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:54:33 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/13 14:27:49 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
  private:
	/*                               ORTHODOX CLASS                           */
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter(void);
	ScalarConverter &operator=(const ScalarConverter &copy);

	/*                               METHODS                                  */
	static bool isChar(const std::string &str);
	static bool isValid(const std::string &str);
	static void printCharInput(const std::string &str);
	static void printChar(double c);
	static void printInt(double c);
	static void printFloat(double c);
	static void printDouble(double c);

  public:
	/*                               METHODS                                  */
	static void convert(std::string &toConvert);
};

#endif
