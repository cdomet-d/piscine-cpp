/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:48:06 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testBureaucrats(void);
void testForms(void);
void testFormSignature(void);

int main(int ac, char *av[]) {
	std::string input;

	if (ac != 2) {
		std::cout << "To test Bureaucrat Creation, type 1" << std::endl
				  << "To test Forms Creation: type 2" << std::endl
				  << "To test Form signature: type 3" << std::endl;
		return (1);
	}
	input = av[1];
	if (input.compare("1") == 0)
		testBureaucrats();
	else if (input.compare("2") == 0)
		testForms();
	else if (input.compare("3") == 0)
		testFormSignature();
	else
		std::cout << "/!\\ Unknown command: " << input << std::endl;
	return (0);
}
