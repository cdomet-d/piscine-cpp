/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:24:14 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/28 16:46:10 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void) {
	Point a(2.18, 1.63);
	Point b(4.5, 4);
	Point c(10.68, 3.55);
	Point point(10.6722226452848, 3.5474439594559);
	std::cout << point << std::endl;
	try {
		if (bsp(a, b, c, point) ==  true)
			std::cout << "Point is inside the triangle" << std::endl;
		else
			std::cout << "Point is outside the triangle" << std::endl;
	}
	catch (std::invalid_argument& ia) {
		std::cout << ia.what() << std::endl;
	}
} 