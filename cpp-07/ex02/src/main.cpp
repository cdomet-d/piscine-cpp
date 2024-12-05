/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/05 16:43:46 by cdomet-d         ###   ########lyon.fr   */
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
	// {
	// 	Array<int> arr(10);

	// 	for (unsigned long i = 0; i < arr.size(); i++)
	// 		std::cout << arr[i] << " ";
	// 	std::cout << std::endl;
	// }

	// {
	// 	Array<float> arr(10);

	// 	arr.fill(5.0f);
	// 	for (unsigned long i = 0; i < arr.size(); i++)
	// 		std::cout << std::fixed << std::showpoint << std::setprecision(1)
	// 				  << arr[i] << " ";
	// 	std::cout << std::endl;
	// }

	// {
	// 	Array<char> arr(10);

	// 	arr.fill('c');
	// 	for (unsigned long i = 0; i < arr.size(); i++)
	// 		std::cout << arr[i] << " ";
	// 	std::cout << std::endl;
	// }

	// {
	// 	Array<char> arr(10);
	// 	arr.fill('c');

	// 	Array<char> cpy(arr);

	// 	printArr("arr", arr);
	// 	printArr("cpy", cpy);

	// 	std::cout << "Filling cpy with 'a'" << std::endl;
	// 	cpy.fill('a');

	// 	printArr("arr", arr);
	// 	printArr("cpy", cpy);

	// 	std::cout << "Filling arr with '*'" << std::endl;

	// 	arr.fill('*');
	// 	printArr("arr", arr);
	// 	printArr("cpy", cpy);
	// }

	{
		Array<int> arr(10);
		Array<int> cpy(10);

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
	}
}
