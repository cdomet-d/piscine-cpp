/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/10 09:46:47 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "iomanip"

template < typename Arr >
static void printArr(const char *s, const Arr &arr)
{
	std::cout << s << ": ";
	for (unsigned long i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int main()
{
	{
		std::cout << "Empty array of 10 int" << std::endl;
		Array< int > arr;

		printArr("arr", arr);
		std::cout << std::endl;
	}
	{
		std::cout << "Empty array of 10 int" << std::endl;
		Array< int > arr(10);

		printArr("arr", arr);
		std::cout << std::endl;
	}

	{
		Array< std::string > arr(5);
		arr.fill("Super fun |");
		std::cout << "Array of 5 std::string filled with a message"
				  << std::endl;

		printArr("arr", arr);
		std::cout << std::endl;
	}

	{
		Array< char > arr(10);
		arr.fill('c');

		std::cout << "Array of 10 char filled with 'c'" << std::endl;
		printArr("arr", arr);
		std::cout << std::endl;
	}

	{
		Array< char > arr(10);
		arr.fill('c');
		std::cout << "Testing cpy constructor with char[10] filled with 'c'"
				  << std::endl;

		Array< char > cpy(arr);
		printArr("arr", arr);
		printArr("cpy", cpy);

		std::cout << "Filling cpy with 'a'" << std::endl;
		cpy.fill('a');

		printArr("arr", arr);
		printArr("cpy", cpy);

		std::cout << "Filling arr with '*'" << std::endl;

		arr.fill('*');
		printArr("arr", arr);
		printArr("cpy", cpy);
		std::cout << std::endl;
	}

	{
		Array< int > arr(10);
		Array< int > cpy(5);

		std::cout << "Testing operator=() constructor with arr[10] = {45} && "
					 "cpy[5] = {18}"
				  << std::endl;
		arr.fill(45);
		cpy.fill(18);
		printArr("arr", arr);
		printArr("cpy", cpy);

		std::cout << "arr = cpy" << std::endl;
		arr = cpy;
		printArr("arr", arr);
		printArr("cpy", cpy);

		std::cout << "Filling arr with '99' to verify deep copy" << std::endl;

		arr.fill(99);
		printArr("arr", arr);
		printArr("cpy", cpy);
		std::cout << std::endl;
	}

	{
		Array< int > arr(10);
		arr.fill(85);
		std::cout << "Testing OOB indexes" << std::endl;
		try {
			std::cout << arr[20] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}
