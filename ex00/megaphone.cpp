/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:44:58 by jauseff           #+#    #+#             */
/*   Updated: 2024/07/02 17:55:10 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char *av[])
{
	size_t	i = 1;
	size_t	j = 0;

	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (av[i])	
		{
			j = 0;
			while (av[i][j])
				std::cout << static_cast<char>(std::toupper(av[i][j++]));
			i++;
		}
	}
	std::cout << std::endl;
}
