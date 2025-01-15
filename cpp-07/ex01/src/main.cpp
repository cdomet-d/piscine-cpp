/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 18:06:47 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 10:52:08 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	{
		char arr[50] = "This is very funny and interesting <:)";
		inter(arr, 50, print< char >);
		std::cout << std::endl;
	}
	{
		int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		inter(arr, 10, print< int >);
		std::cout << std::endl;
	}
	{
		std::string arr[3] = {"Fun !!\n", "So much fun !!!\n",
							  "I love testing !!\n"};
		inter(arr, 3, print< std::string >);
		std::cout << std::endl;
	}
}