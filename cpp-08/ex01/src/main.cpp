/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:07 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 13:46:40 by cdomet-d         ###   ########.fr       */
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
	try {
		if (arg.compare("1") == 0) {
			unsigned int val[] = {5, 979, 506, 397, 52, 266, 899};
			std::vector< unsigned int > src(
				val, val + sizeof(val) / sizeof(unsigned int));
			{
				Span span(src.size());
				errorHandling(span, src);
			}
			{
				std::cout << std::endl << "TESTING DEEP COPY" << std::endl;
				Span span(src.size());
				span.fillSpan(span.getSpanBegin(), src.begin(), src.end());
				deepCopy(span);
			}
			return 0;
		} else if (arg.compare("2") == 0) {
			largeArr("src/source-arrays/1000");
			return 0;
		} else if (arg.compare("3") == 0) {
			largeArr("src/source-arrays/10000");
			return 0;
		} else if (arg.compare("4") == 0) {
			largeArr("src/source-arrays/100000");
			return 0;
		} else {
			std::cout << "Please provide a parameter:" << std::endl
					  << "Enter [1]	to check error handling & deep copy"
					  << std::endl
					  << "Enter [2]	to check a Span of 1000" << std::endl
					  << "Enter [3]	to check a Span of 10000" << std::endl
					  << "Enter [4]	to check a Span of 100000" << std::endl;
			return 1;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
