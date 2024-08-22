/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:02:39 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/08/22 16:48:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.cpp"

int main( void ) {
	Fixed a(15.5f);
	Fixed b(15.51f);

	std::cout << a << " | " << b << std::endl;
	if (a == b)
		std::cout << "Yay !" << std::endl;
	else
		std::cout << "Aww :(" << std::endl;
	return 0;
}