/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:50:45 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/04 13:37:37 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "templates.hpp"
#include <iostream>

#define BR "\033[1m\033[31m"
#define R "\033[0m"
#define BG "\033[1m\033[33m"

void testSwap()
{
	{
		int a = 15;
		int b = 5;

		std::cout << "Testing swap(T a, T b) with int values"
				  << std::endl
				  << "Original values:	" << a << "	|	" << b << std::endl;
		swap(a, b);
		std::cout << BG "After swap:		" << a << "	|	" << b << R << std::endl
				  << std::endl;
	}

	{
		float a = 15.5f;
		float b = 50.9f;

		std::cout << "Testing swap(T a, T b) with float values"
				  << std::endl
				  << "Original values:	" << a << "	|	" << b << std::endl;
		swap(a, b);
		std::cout << BG "After swap:		" << a << "	|	" << b << R << std::endl
				  << std::endl;
	}

	{
		std::string a = "What a wonderful world";
		std::string b = "Not the same string :)";

		std::cout << "Testing swap(T a, T b) with std::string values"
				  << std::endl
				  << "Original values:	" << a << "	|	" << b << std::endl;
		swap(a, b);
		std::cout << BG "After swap:		" << a << "	|	" << b << R << std::endl;
	}
}

void testMin()
{
	{
		int a = 15;
		int b = 5;

		std::cout << "Testing min(T a, T b) with int values"
				  << std::endl
				  << "The smallest of " << a << " and " << b << " is	" << BG << min(a, b) << R << std::endl
				  << std::endl;
	}

	{
		float a = 15.5f;
		float b = 50.9f;

		std::cout << "Testing min(T a, T b) with float values"
				  << std::endl
				  << "The smallest of " << a << " and " << b << " is	" << BG << min(a, b) << R << std::endl
				  << std::endl;
	}

	{
		char a = 'w';
		char b = '*';

		std::cout << "Testing min(T a, T b) with char values"
				  << std::endl
				  << "The smallest of " << a << " and " << b << " is	" << BG << min(a, b) << R << std::endl
				  << std::endl;
	}

	{
		char a = 'w';
		char b = 'w';

		std::cout << "Testing min(T a, T b) with equal char values"
				  << std::endl
				  << "The smallest of " << a << " and " << b << " is	" << BG << min(a, b) << R << std::endl;
	}
}

void testMax()
{
	{
		int a = 15;
		int b = 5;

		std::cout << "Testing max(T a, T b) with int values"
				  << std::endl
				  << "The greater of " << a << " and " << b << " is	" << BG << max(a, b) << R << std::endl
				  << std::endl;
	}

	{
		float a = 15.5f;
		float b = 50.9f;

		std::cout << "Testing max(T a, T b) with float values"
				  << std::endl
				  << "The greater of " << a << " and " << b << " is	" << BG << max(a, b) << R << std::endl
				  << std::endl;
	}

	{
		char a = 'w';
		char b = '*';

		std::cout << "Testing max(T a, T b) with char values"
				  << std::endl
				  << "The greater of " << a << " and " << b << " is	" << BG << max(a, b) << R << std::endl
				  << std::endl;
	}

	{
		char a = 'w';
		char b = 'w';

		std::cout << "Testing max(T a, T b) with equal char values"
				  << std::endl
				  << "The smallest of " << a << " and " << b << " is	" << BG << min(a, b) << R << std::endl;
	}
}

void mandatoryMain(void)
{
	{
		std::cout << "Expected output:" << std::endl
				  << "a = 3, b = 2\nmin( a, b ) = 2\nmax( a, b ) = 3\nc = chaine2, \
d = chaine1\nmin( c, d ) = chaine1\nmax( c, d ) = chaine2\n"
				  << std::endl;
	}

	std::cout
		<< "Program output:" << std::endl;

	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}