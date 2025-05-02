/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:51:48 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:57:22 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

#define TEST_MUTANT(Container, Type, SubContainer, Instance, Method)           \
	std::cout << "" #Container "<" #Type ", " #SubContainer "> > " #Instance   \
				 ""                                                            \
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
		std::cout << *it << " ";                                               \
		++it;                                                                  \
	}                                                                          \
	std::cout << std::endl << std::endl;                                       \
	std::stack< Type, SubContainer< Type > > s(Instance);

template < typename iterator >
static void printCont(iterator beg, const iterator end) {

	while (beg != end) {
		std::cout << *beg << " ";
		++beg;
	}
	std::cout << std::endl;
}
int main(void) {
	{ TEST_MUTANT(MutantStack, int, std::deque, mstack, push); }
	{ TEST_MUTANT(MutantStack, int, std::list, mstack, push); }
	{ TEST_MUTANT(MutantStack, int, std::vector, mstack, push); }

	{
		std::cout << "Testing copying" << std::endl;
		MutantStack< int > mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack< int >::const_iterator it = mstack.begin();
		MutantStack< int >::const_iterator ite = mstack.end();
		++it;
		--it;

		std::cout << "Printing mstack" << std::endl;

		while (it != ite) {
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::cout << "Creating cpy from mstack and adding some values"
				  << std::endl;
		MutantStack< int > cpy(mstack);
		cpy.push(999);

		std::cout << "Printing cpy" << std::endl;
		for (MutantStack< int >::iterator begin = cpy.begin();
			 begin != cpy.end(); ++begin) {
			std::cout << *begin << " ";
			++it;
		}
		std::cout << std::endl;
		std::stack< int > s(mstack);
		std::cout << std::endl;
	}

	{
		std::cout << "Comparison with std::list<int>" << std::endl;
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
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::list< int > s(nlist);
		std::cout << std::endl;
	}

	{
		std::cout << "Testing reverse iterators" << std::endl;
		MutantStack< int > mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		{
			MutantStack< int >::iterator it = mstack.begin();
			MutantStack< int >::iterator ite = mstack.end();
			std::cout << "Forward way" << std::endl;
			while (it != ite) {
				std::cout << *it << " ";
				++it;
			}
			std::cout << std::endl;
		}

		{
			MutantStack< int >::reverse_iterator it = mstack.rbegin();
			MutantStack< int >::reverse_iterator ite = mstack.rend();
			std::cout << "Reverse way" << std::endl;
			while (it != ite) {
				std::cout << *it << " ";
				++it;
			}
			std::cout << std::endl;
		}

		MutantStack< int > s(mstack);
		std::cout << std::endl;
	}
}
