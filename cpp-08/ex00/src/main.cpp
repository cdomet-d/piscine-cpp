/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:39:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 10:50:42 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

#include <list>
#include <stack>
#include <vector>

int main()
{
	int values[] = {5,	 979, 506, 397, 52,	 266, 899, 355, 687, 188, 898, 376,
					815, 487, 788, 477, 623, 743, 950, 488, 94,	 62,  384, 907,
					901, 688, 965, 841, 956, 584, 489, 607, 193, 767, 852, 365,
					270, 127, 193, 790, 833, 617, 615, 352, 623};
	{
		int seek = 623;
		{
			std::cout << "Test for std::vector" << std::endl;
			const std::vector< int > arr(values,
										 values + sizeof(values) / sizeof(int));
			std::vector< int >::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}

		{
			std::cout << "Test for std::list" << std::endl;
			const std::list< int > arr(values,
									   values + sizeof(values) / sizeof(int));
			std::list< int >::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}

		{
			std::cout << "Test for std::deque" << std::endl;
			const std::deque< int > arr(values,
										values + sizeof(values) / sizeof(int));
			std::deque< int >::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}
	}

	{
		int seek = -8;
		{
			std::cout << "Test for std::vector" << std::endl;
			const std::vector< int > arr(values,
										 values + sizeof(values) / sizeof(int));
			std::vector< int >::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}

		{
			std::cout << "Test for std::list" << std::endl;
			const std::list< int > arr(values,
									   values + sizeof(values) / sizeof(int));
			std::list< int >::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}

		{
			std::cout << "Test for std::deque" << std::endl;
			const std::deque< int > arr(values,
										values + sizeof(values) / sizeof(int));
			std::deque< int >::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}
	}

	{
		int seek = -8;

		std::cout << "Test for empty containers :" << std::endl;
		const std::vector< int > arr;

		std::vector< int >::const_iterator found = easyFind(arr, seek);

		printArr(arr, seek);
		if (found == arr.end())
			std::cout << seek << " not found in arr" << std::endl;
		else
			std::cout << seek << " found at pos "
					  << std::distance(arr.begin(), found) << std::endl;
		std::cout << std::endl;
	}
}