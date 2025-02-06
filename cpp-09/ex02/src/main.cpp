/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:05:23 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/06 17:02:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"

#include <deque>
#include <vector>
#include <iostream>

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cerr << "Usage: ./mergeInsert \"5 1 2 [..] 66 42 3 0\""
				  << std::endl;
		return 1;
	}
	try {
		MergeInsert< std::deque > deq(av + 1);
		deq.sort("deque");
		MergeInsert< std::vector > vec(av + 1);
		vec.sort("vector");
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
