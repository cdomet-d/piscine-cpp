/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:39 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/23 18:31:37 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.cpp"

void testArithmetic(void) {
	Fixed a(2.5f);
	Fixed b(5.45f);
	Fixed c;
	c = a + b;
	std::cout	<< "| Additions |" << std::endl
				<< a << " + " << b << " = " << c << std::endl
				<< a << " + " << b << " = " << c << std::endl
				<< a << " + " << c << " = " << a + c << std::endl
				<< c << " + " << "5.95" << " = " << c + 5.95f << std::endl
				<< std::endl << "| Substractions |" << std::endl
				<< a << " - " << b << " = " << a - b << std::endl
				<< c << " - " << a << " = " << c - a << std::endl
				<< a << " - " << c << " = " << a - c << std::endl
				<< c << " - " << "5.95" << " = " << c - 5.95f << std::endl
				<< std::endl << "| Multiplication |" << std::endl
				<< "1.23" << " * " << "5.95" << " = " << Fixed(1.23f) * Fixed(5.95f) << std::endl
				<< "7" << " * " << "6.5" << " = " << Fixed(7) * Fixed(6.5f) << std::endl
				<< "5.8" << " * " << "40" << " = " << Fixed(5.8f) * Fixed(40) << std::endl
				<< "1" << " * " << "2.5" << " = " << Fixed(1) * Fixed(2.5f) << std::endl
				<< std::endl << "| Division |" << std::endl
				<< "5" << " / " << "2.5" << " = " << Fixed(5) / Fixed(2.5f) << std::endl
				<< "7" << " / " << "1.5" << " = " << Fixed(7) / Fixed(1.5f) << std::endl
				<< "5.8" << " / " << "40" << " = " << Fixed(5.8f) / Fixed(40) << std::endl
				<< "10" << " / " << "2.5" << " = " << Fixed(10) / Fixed(2.5f) << std::endl
				<< std::endl;
}

int main( void ) {
	Fixed a(10);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	testArithmetic();
	//TODO: write comparison tests
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	try {
		std::cout << a / 0 << std::endl;
	}
	catch (std::invalid_argument const& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}