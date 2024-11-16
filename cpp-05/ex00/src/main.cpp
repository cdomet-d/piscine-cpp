/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:43:18 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/11/16 15:29:15 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat One = Bureaucrat("One", 1);
	Bureaucrat Two = Bureaucrat("Two", 150);

	One++;
	Two++;
	std::cout << One << std::endl;
	std::cout << Two << std::endl;

	One--;
	Two--;
	std::cout << One << std::endl;
	std::cout << Two << std::endl;
}