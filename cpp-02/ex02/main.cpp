/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:39 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/29 14:52:59 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.cpp"

static void testArithmetic(void)
{
	Fixed a(2.5f);
	Fixed b(5.50f);
	Fixed c;

	c = a + b;
	std::cout << "| Additions |" << std::endl
			  << a << " + " << b << " = " << c << std::endl
			  << a << " + " << b << " = " << c << std::endl
			  << a << " + " << c << " = " << a + c << std::endl
			  << c << " + " << "5.95" << " = " << c + 5.95f << std::endl

			  << std::endl
			  << "| Substractions |" << std::endl
			  << a << " - " << b << " = " << a - b << std::endl
			  << c << " - " << a << " = " << c - a << std::endl
			  << a << " - " << c << " = " << a - c << std::endl
			  << c << " - " << "5.95" << " = " << c - 5.95f << std::endl

			  << std::endl
			  << "| Multiplication |" << std::endl
			  << "1.23" << " * " << "5.95" << " = " << Fixed(1.23f) * Fixed(5.95f) << std::endl
			  << "7" << " * " << "6.5" << " = " << Fixed(7) * Fixed(6.5f) << std::endl
			  << "5.8" << " * " << "40" << " = " << Fixed(5.8f) * Fixed(40) << std::endl
			  << "1" << " * " << "2.5" << " = " << Fixed(1) * Fixed(2.5f) << std::endl

			  << std::endl
			  << "| Division |" << std::endl
			  << "5" << " / " << "2.5" << " = " << Fixed(5) / Fixed(2.5f) << std::endl
			  << "7" << " / " << "1.5" << " = " << Fixed(7) / Fixed(1.5f) << std::endl
			  << "5.8" << " / " << "40" << " = " << Fixed(5.8f) / Fixed(40) << std::endl
			  << "10" << " / " << "2.5" << " = " << Fixed(10) / Fixed(2.5f) << std::endl
			  << std::endl;
}

static void testMinMax(void)
{
	std::cout << std::endl
			  << "| Non const MinMax |" << std::endl;
	{
		Fixed a(3.0f);
		Fixed b(5.6f);
		std::cout << a << " | " << b << " || Max is: " << Fixed::max(a, b) << std::endl;
		std::cout << a << " | " << b << " || Min is: " << Fixed::min(a, b) << std::endl;
	}
	std::cout << std::endl
			  << "| Const MinMax |" << std::endl;
	{
		const Fixed a(3.0f);
		const Fixed b(5.52f);
		std::cout << a << " | " << b << " || Max is: " << Fixed::max(a, b) << std::endl;
		std::cout << a << " | " << b << " || Min is: " << Fixed::min(a, b) << std::endl;
	}
}

static void providedMain(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << std::endl
			  << "| Module provided main |" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

int main(void)
{
	testArithmetic();
	testMinMax();
	providedMain();
	return 0;
}