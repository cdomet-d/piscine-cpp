/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/07 12:09:07 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main()
{
	{
		std::cout << "> char array -----" << std::endl;
		char arr[50] = "This is very funny and interesting <:)";
		iter(arr, 50, print< char >);
		std::cout << std::endl;
	}
	{
		std::cout << "> int array -----" << std::endl;
		int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		iter(arr, 10, print< int >);
		std::cout << std::endl;
	}
	{
		std::cout << "> std::string array -----" << std::endl;
		std::string arr[3] = {"Fun !! | ", "So much fun !!! |",
							  "I love testing !! |"};
		iter(arr, 3, print< std::string >);
		std::cout << std::endl;
	}
	{
		std::cout << "> const int array -----" << std::endl;
		const int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		iter(arr, 10, print< const int >);
		std::cout << std::endl;
	}
}
