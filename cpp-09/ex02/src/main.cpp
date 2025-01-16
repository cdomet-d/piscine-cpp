/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:05:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/16 17:28:56 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"
#include <deque>
#include <iostream>
#include <vector>

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cerr << "Usage: ./mergeInsert \"5 1 2 [..] 66 42 3 0\""
				  << std::endl;
		return 1;
	}
	std::string arg = av[1];
}
