/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/29 15:44:35 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data square = {10, 10, 10, 0, 0};

	std::cout << "Creating Data square = {10, 10, 10, 0, 0}:" << std::endl
			  << square << std::endl
			  << std::endl;

	uintptr_t sraw = 0;
	std::cout << "Creating uintptr_t sraw: " << sraw
			  << std::endl;
	sraw = Serializer::serialize(&square);
	std::cout << "After serializing square in sraw: " << sraw << std::endl
			  << std::endl;

	Data nsquare = {45, 45, 45, 20, 20};
	Data *new_square = &nsquare;
	std::cout << "Creating Data nsquare = {45, 45, 45, 20, 20}; \
and Data *new_square = &nsquare;"
			  << std::endl
			  << "Printing *new_square"
			  << std::endl
			  << *new_square << std::endl
			  << std::endl;

	new_square = Serializer::deserialize(sraw);

	std::cout << "Printing *new_square after deserialization" << std::endl
			  << *new_square << std::endl;
	return 0;
}
