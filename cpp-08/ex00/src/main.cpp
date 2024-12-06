/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:39:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/06 14:36:41 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

#include <list>
#include <stack>
#include <vector>

int main()
{
	int values[] = {5, 10, 15, 20, 25, -5, -10, -15};
	{
		int seek = 20;
		{
			std::cout << "Test for std::vector" << std::endl;
			const std::vector<int> arr(values,
									   values + sizeof(values) / sizeof(int));
			std::vector<int>::const_iterator found = easyFind(arr, seek);

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
			const std::list<int> arr(values,
									 values + sizeof(values) / sizeof(int));
			std::list<int>::const_iterator found = easyFind(arr, seek);

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
			const std::deque<int> arr(values,
									  values + sizeof(values) / sizeof(int));
			std::deque<int>::const_iterator found = easyFind(arr, seek);

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
			const std::vector<int> arr(values,
									   values + sizeof(values) / sizeof(int));
			std::vector<int>::const_iterator found = easyFind(arr, seek);

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
			const std::list<int> arr(values,
									 values + sizeof(values) / sizeof(int));
			std::list<int>::const_iterator found = easyFind(arr, seek);

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
			const std::deque<int> arr(values,
									  values + sizeof(values) / sizeof(int));
			std::deque<int>::const_iterator found = easyFind(arr, seek);

			printArr(arr, seek);
			if (found == arr.end())
				std::cout << seek << " not found in arr" << std::endl;
			else
				std::cout << seek << " found at pos "
						  << std::distance(arr.begin(), found) << std::endl;
			std::cout << std::endl;
		}
	}
}