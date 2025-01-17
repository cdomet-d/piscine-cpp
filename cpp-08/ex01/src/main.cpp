/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:07 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/15 10:54:07 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "unitTest.hpp"

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Please provide a parameter:" << std::endl
				  << "Enter [1]	to check error handling" << std::endl
				  << "Enter [2]	to check a Span of 1000" << std::endl
				  << "Enter [3]	to check a Span of 10000" << std::endl
				  << "Enter [4]	to check a Span of 100000" << std::endl;
		return 1;
	}
	std::string arg = av[1];
	if (arg.compare("1") == 0) {
		unsigned int val[] = {5,   979, 506, 397, 52,  266, 899, 355,
							  687, 188, 898, 376, 815, 487, 788, 477,
							  623, 743, 950, 488, 94,  62,	384};
		std::vector< unsigned int > src(val, val + sizeof(val) / sizeof(int));
		Span span(src.size());
		errorHandling(span, src);
		return 0;
	}
	if (arg.compare("2") == 0)
		largeArr("src/source-arrays/1000");
	else if (arg.compare("3") == 0)
		largeArr("src/source-arrays/10000");
	else if (arg.compare("4") == 0)
		largeArr("src/source-arrays/100000");
	else {
		std::cout << "Please provide a parameter:" << std::endl
				  << "Enter [1]	to check error handling" << std::endl
				  << "Enter [2]	to check a Span of 1000" << std::endl
				  << "Enter [3]	to check a Span of 10000" << std::endl
				  << "Enter [4]	to check a Span of 100000" << std::endl;
		return 1;
	}
}
