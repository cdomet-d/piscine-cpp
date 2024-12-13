/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/12/13 14:57:47 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

#define TEST_MUTANT(Container, Type, SubContainer, Instance, Method)           \
	std::cout << std::endl                                                     \
			  << "" #Container "<" #Type ", " #SubContainer "> > " #Instance   \
				 ""                                                            \
			  << std::endl                                                     \
			  << std::endl;                                                    \
	Container< Type, SubContainer< Type > > Instance;                          \
	Instance.Method(5);                                                        \
	Instance.Method(17);                                                       \
	std::cout << Instance.top() << std::endl;                                  \
	Instance.pop();                                                            \
	std::cout << Instance.size() << std::endl;                                 \
	Instance.Method(3);                                                        \
	Instance.Method(5);                                                        \
	Instance.Method(737);                                                      \
	Instance.Method(0);                                                        \
	Container< Type, SubContainer< Type > >::iterator it = Instance.begin();   \
	Container< Type, SubContainer< Type > >::iterator ite = Instance.end();    \
	++it;                                                                      \
	--it;                                                                      \
	while (it != ite) {                                                        \
		std::cout << *it << std::endl;                                         \
		++it;                                                                  \
	}                                                                          \
	std::stack< Type, SubContainer< Type > > s(Instance);

int main(void)
{
	{TEST_MUTANT(MutantStack, int, std::deque, mstack, push);}
	{TEST_MUTANT(MutantStack, int, std::list, mstack, push);}
	{TEST_MUTANT(MutantStack, int, std::vector, mstack, push);}

	{
		std::cout << std::endl
				  << "Comparison with std::list<int>" << std::endl
				  << std::endl;
		std::list< int > nlist;
		nlist.push_back(5);
		nlist.push_back(17);
		std::cout << nlist.back() << std::endl;
		nlist.pop_back();
		std::cout << nlist.size() << std::endl;
		nlist.push_back(3);
		nlist.push_back(5);
		nlist.push_back(737);
		nlist.push_back(0);
		std::list< int >::iterator it = nlist.begin();
		std::list< int >::iterator ite = nlist.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::list< int > s(nlist);
		return 0;
	}
}
