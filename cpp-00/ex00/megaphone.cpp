/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:44:58 by jauseff           #+#    #+#             */
/*   Updated: 2025/05/02 15:46:20 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int ac, char *av[]) {

	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		size_t i = 1;
		size_t j = 0;
		while (av[i]) {
			j = 0;
			while (av[i][j])
				std::cout << static_cast< char >(std::toupper(av[i][j++]));
			i++;
		}
	}
	std::cout << std::endl;
}
