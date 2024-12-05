/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/05 17:34:03 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "iomanip"

template <typename T>
static void printArr(const char *s, const T &arr)
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
		Array<int> arr(10);

		printArr("arr", arr);
		std::cout << std::endl;
	}

	{
		Array<std::string> arr(5);
		arr.fill("Super fun |");
		std::cout << "Array of 10 std::string filled with a message"
				  << std::endl;

		printArr("arr", arr);
		std::cout << std::endl;
	}

	{
		Array<char> arr(10);
		arr.fill('c');

		std::cout << "Array of 10 char filled with 'c'" << std::endl;
		printArr("arr", arr);
		std::cout << std::endl;
	}

	{
		Array<char> arr(10);
		arr.fill('c');
		std::cout << "Testing cpy constructor with char[10] filled with 'c'"
				  << std::endl;

		Array<char> cpy(arr);
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
		Array<int> arr(10);
		Array<int> cpy(5);

		std::cout << "Testing operator=() constructor with arr[10] = {45} && "
					 "cpy[5] = {18} filled with 'c'"
				  << std::endl;
		arr.fill(45);
		cpy.fill(18);
		printArr("arr", arr);
		printArr("cpy", cpy);

		std::cout << "arr = cpy" << std::endl;
		arr = cpy;
		printArr("arr", arr);
		printArr("cpy", cpy);

		std::cout << "Filling arr with '99'" << std::endl;

		arr.fill(99);
		printArr("arr", arr);
		printArr("cpy", cpy);
		std::cout << std::endl;
	}

	{
		Array<int> arr(10);
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
