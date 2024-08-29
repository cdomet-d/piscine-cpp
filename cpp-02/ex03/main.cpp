/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:24:14 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/29 10:06:24 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

# define GREEN "\e[32m"
# define RED "\e[31m"
# define R "\033[0m"

static void validTests(void) {
	Point a(37.2169225000001, 21.18598);
	Point b(13.588345, 18.31102);
	Point c(17.00236, 2.7682675);
	
	{
		Point F(-1, -0.8);
		try {
			if (bsp(a, b, c, F) ==  true)
				std::cout << GREEN << "F is inside the triangle" << R << std::endl << std::endl;
			else
				std::cout << RED << "F is outside the triangle" << R << std::endl << std::endl;
		}
		catch (std::invalid_argument& ia) {
			std::cout << ia.what() << std::endl;
		}
	}
	
	{
		Point G(5.7720475, 5.553385);

		try {
			if (bsp(a, b, c, G) ==  true)
				std::cout << GREEN << "G is inside the triangle" << R << std::endl << std::endl;
			else
				std::cout << RED << "G is outside the triangle" << R << std::endl << std::endl;
		}
		catch (std::invalid_argument& ia) {
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point H(25.341468540269, 10.3648897145952);
		try {
			if (bsp(a, b, c, H) ==  true)
				std::cout << GREEN << "H is inside the triangle" << R << std::endl << std::endl;
			else
				std::cout << RED << "H is outside the triangle" << R << std::endl << std::endl;
		}
		catch (std::invalid_argument& ia) {
			std::cout << ia.what() << std::endl;
		}
	}
	
	{
		Point E(20, 15);
		try {
			if (bsp(a, b, c, E) ==  true)
				std::cout << GREEN << "E is inside the triangle" << R << std::endl << std::endl;
			else
				std::cout << RED << "E is outside the triangle" << R << std::endl << std::endl;
		}
		catch (std::invalid_argument& ia) {
			std::cout << ia.what() << std::endl;
		}
	}
}

static void invalidTests(void) {
	Point a(37.2169225000001, 21.18598);
	Point b(13.588345, 18.31102);
	Point c(37.2169225000001, 21.18598);

	Point D(23.291335, 33.8537725);
	try {
	if (bsp(a, b, c, D) ==  true)
		std::cout << GREEN << "D is inside the triangle" << R << std::endl << std::endl;
	else
		std::cout << RED << "D is outside the triangle" << R << std::endl << std::endl;
	}
	catch (std::invalid_argument& ia) {
		std::cout << RED << ia.what() << R << std::endl;
	}
}

int main(void) {
	validTests();
	invalidTests();
}
