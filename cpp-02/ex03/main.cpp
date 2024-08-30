/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:24:14 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/30 15:06:25 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define GREEN "\e[32m"
#define RED "\e[31m"
#define R "\033[0m"

static void invalidTests(void)
{
	Point a(4, -4);
	Point b(16.92, 20.97);
	Point c(4, -4);

	std::cout
		<< "a is interpreted as: " << a << std::endl
		<< "b is interpreted as: " << b << std::endl
		<< "c is interpreted as: " << c << std::endl
		<< std::endl;

	Point D(6, -2);
	try
	{
		if (bsp(a, b, c, D) == true)
			std::cout << GREEN << "D is inside the triangle" << R << std::endl
					  << std::endl;
		else
			std::cout << RED << "D is outside the triangle" << R << std::endl
					  << std::endl;
	}
	catch (std::invalid_argument &ia)
	{
		std::cout << RED << ia.what() << R << std::endl;
	}
}

static void validTests(void)
{
	Point a(4, -4);
	Point b(16.92, 20.97);
	Point c(34.356, 11.355);

	std::cout
		<< "a is interpreted as: " << a << std::endl
		<< "b is interpreted as: " << b << std::endl
		<< "c is interpreted as: " << c << std::endl
		<< std::endl;

	Point D(6, -2);
	try
	{
		if (bsp(a, b, c, D) == true)
			std::cout << GREEN << "D is inside the triangle" << R << std::endl
					  << std::endl;
		else
			std::cout << RED << "D is outside the triangle" << R << std::endl
					  << std::endl;
	}
	catch (std::invalid_argument &ia)
	{
		std::cout << RED << ia.what() << R << std::endl;
	}

	{
		Point E(17.5028966871534, 2.4508890990681);
		try
		{
			if (bsp(a, b, c, E) == true)
				std::cout << GREEN << "E is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "E is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point F(30, 14);
		try
		{
			if (bsp(a, b, c, F) == true)
				std::cout << GREEN << "F is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "F is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point G(16.7520797682473, 20.6738824931523);
		try
		{
			if (bsp(a, b, c, G) == true)
				std::cout << GREEN << "G is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "G is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point H(19.9593489242307, 18.7993604176981);
		try
		{
			if (bsp(a, b, c, H) == true)
				std::cout << GREEN << "H is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "H is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point I(13.4577139003887, 13.5863377398983);
		try
		{
			if (bsp(a, b, c, I) == true)
				std::cout << GREEN << "I is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "I is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point J(8.9475706856515, 6.4989698296311);
		try
		{
			if (bsp(a, b, c, J) == true)
				std::cout << GREEN << "J is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "J is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point K(23.1808797919002, 12.004858950004);
		try
		{
			if (bsp(a, b, c, K) == true)
				std::cout << GREEN << "K is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "K is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point M(30.245802200861, 9.2759353242573);
		try
		{
			if (bsp(a, b, c, M) == true)
				std::cout << GREEN << "M is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "M is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point N(13.1551858308877, -0.1751206316028);
		try
		{
			if (bsp(a, b, c, N) == true)
				std::cout << GREEN << "N is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "N is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}

	{
		Point L(3.5576821219659, -4.3314409977844);
		try
		{
			if (bsp(a, b, c, L) == true)
				std::cout << GREEN << "L is inside the triangle" << R << std::endl
						  << std::endl;
			else
				std::cout << RED << "L is outside the triangle" << R << std::endl
						  << std::endl;
		}
		catch (std::invalid_argument &ia)
		{
			std::cout << ia.what() << std::endl;
		}
	}
}

int main(void)
{
	validTests();
	invalidTests();
}
