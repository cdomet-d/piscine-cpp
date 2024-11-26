/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:54:33 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/26 17:30:19 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &copy);
	~ScalarConverter(void);
	ScalarConverter &operator=(const ScalarConverter &copy);

public:
	/*                               ORTHODOX CLASS                           */

	/*                               METHODS                                  */
	static void convert(std::string &toConvert);
	
	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
};

#endif
