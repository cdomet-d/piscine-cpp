/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:24:42 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:46:01 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char *argv[]) {
	Harl test;

	if (ac < 2)
		return (std::cout << "ERROR: No complain level provided" << std::endl,
				1);
	for (size_t i = 1; argv[i]; i++) {
		try {
			test.complain(argv[i]);
		} catch (const std::exception &e) {
			std::cout << "ERROR: " << argv[i] << ": " << e.what() << std::endl;
		}
	}
}