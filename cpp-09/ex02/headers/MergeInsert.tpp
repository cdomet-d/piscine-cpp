/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/30 17:51:25 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"
#include "cerrno"
#include <algorithm>
#include <iomanip>
#include <iostream>

static void printInnerCont(std::vector< int > innerCont)
{
	for (std::vector< int >::iterator it = innerCont.begin();
		 it != innerCont.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
MergeInsert< Container >::MergeInsert()
{
}

template <
	template < typename, typename = std::allocator< int > > class Container >
MergeInsert< Container >::MergeInsert(const std::string &seq) : curElemSize(1)
{
	char *endptr = NULL;
	int64_t n = std::strtod(seq.c_str(), &endptr);
	addValidValue(n, endptr);
	while (*endptr) {
		n = std::strtod(endptr + 1, &endptr);
		addValidValue(n, endptr);
	}
	iSize = container.size();
	if (iSize <= 1)
		throw singleValue();
}

template <
	template < typename, typename = std::allocator< int > > class Container >
MergeInsert< Container >::~MergeInsert(void)
{
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::binarySearch(
	size_t maxRange, Container< Container< int, std::allocator< int > > > &main,
	Container< int > &toInsert)
{
	std::vector< int > maxes;
	size_t last = toInsert.size() - 1;
	for (size_t i = 0; i < maxRange; ++i)
		maxes.push_back(main[i][last]);
	std::vector< int >::iterator insertionIt = std::lower_bound(
		maxes.begin(), maxes.begin() + maxRange, toInsert[last]);
	size_t insIndex = std::distance(maxes.begin(), insertionIt);
	main.insert(main.begin() + insIndex, toInsert);
	aIndex.update(insIndex);
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::fillMain(
	Container< Container< int, std::allocator< int > > > &cont)
{
	splitPairs(cont);
	hasStraggler = (cont[cont.size() - 1].size() != curElemSize);
	Container< Container< int, std::allocator< int > > > main;

	printContainer(container, "Entering sort");
	main.push_back(cont[0]);
	aIndex.add(-1);
	aIndex.add(-1);
	for (size_t i = 1; (i < cont.size() && (cont[i].size() == curElemSize));
		 ++i) {
		if (i % 2) {
			main.push_back(cont[i]);
		}
		aIndex.add(i);
	}
	printContainer(main, "Main");
	printContainer(cont, "Container");
	for (size_t i = 2; (i < cont.size() && (cont[i].size() == curElemSize));
		 ++i) {
		if (!(i % 2)) {
			std::cout << "sorting cont[" << i << "]:" << std::endl;
			printInnerCont(cont[i]);
			std::cout << "should be paired with:" << std::endl;
			printInnerCont(main[aIndex.getMaxRange(i)]);
			binarySearch(aIndex.getMaxRange(i), main, cont[i]);
			printContainer(main, "after inserting an element");
		}
	}
	while (hasStraggler && cont[(cont.size() - 1)].size() >= curElemSize) {
		Container< int > stragglerElem =
			halfElemInStraggler(cont[(cont.size() - 1)]);
		if (stragglerElem.size() == curElemSize)
			binarySearch(main.size(), main, stragglerElem);
		main.push_back(cont[(cont.size() - 1)]);
	}
	container = main;
	printContainer(container, "Container, exiting sort");
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::splitPairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	hasStraggler = (cont[cont.size() - 1].size() != curElemSize);

	Container< Container< int, std::allocator< int > > > splitPairs;

	size_t j = 0;
	curElemSize /= PAIR;
	printContainer(cont, "this->cont, right before loop splitting pairs");
	for (size_t i = 0; cont[j].size() == (curElemSize * 2); ++i) {
		if (i % 2) {
			Container< int > newPair((cont[j].begin() + (curElemSize)),
									 cont[j].end());
			splitPairs.push_back(newPair);
		} else {
			Container< int > newPair(cont[j].begin(),
									 (cont[j].begin() + (curElemSize)));
			splitPairs.push_back(newPair);
		}
		j += (i % 2);
	}
	// printContainer(splitPairs, "splitPairs, after splittingPairs");
	// printContainer(container, "container, after splittingPairs");
	if (hasStraggler) {
		makeElemFromStraggler(splitPairs);
		Container< int > straggler(cont[(cont.size() - 1)].begin(),
								   cont[(cont.size() - 1)].end());
		splitPairs.push_back(straggler);
	}
	cont = splitPairs;
	// printContainer(cont, "this->cont, exiting splitPairs");
}

template <
	template < typename, typename = std::allocator< int > > class Container >
Container< int >
MergeInsert< Container >::halfElemInStraggler(Container< int > &straggler)
{
	if (straggler.size() >= curElemSize) {
		Container< int > elemFromStraggler(straggler.begin(),
										   straggler.begin() + curElemSize);
		straggler.erase(straggler.begin(), straggler.begin() + curElemSize);
		std::cout << "Got element of size " << elemFromStraggler.size()
				  << " from straggler" << std::endl;
		printInnerCont(elemFromStraggler);
		return elemFromStraggler;
	}
	return straggler;
}

template <
	template < typename, typename = std::allocator< int > > class Container >
bool MergeInsert< Container >::makeElemFromStraggler(
	Container< Container< int, std::allocator< int > > > &splitPairs)
{
	size_t back = container.size() - 1;

	if (container[back].size() < (curElemSize)) {
		return false;
	}
	size_t canMakeElem = container[back].size() / curElemSize;

	if (canMakeElem % 2)
		canMakeElem -= 1;
	while (canMakeElem != 0) {
		Container< int > newPair(container[back].begin(),
								 container[back].begin() + curElemSize);
		splitPairs.push_back(newPair);
		container[back].erase(container[back].begin(),
							  container[back].begin() + curElemSize);
		canMakeElem--;
	}
	return true;
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::makePairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t pairLevel = cont.size() / PAIR;

	if (curElemSize > 1) {
		// std::cout << "Making pairs of: " << curElemSize << std::endl;
		while (i < pairLevel && (cont.size() - i >= PAIR)) {
			cont[i].insert(cont[i].end(), cont[i + 1].begin(),
						   cont[i + 1].end());
			cont.erase(cont.begin() + i + 1);
			i++;
			// std::cout << "After creating pair:\n---\n";
			// printContainer(cont);
		}
		size_t last = cont.size() - 1;
		if (cont.size() > 1 && cont[last - 1].size() < curElemSize) {
			cont[last - 1].insert(cont[last - 1].end(), cont[last].begin(),
								  cont[last].end());
			cont.erase(cont.begin() + last);
			// std::cout << "After dealing with straggler:\n---\n";
			// printContainer(cont);
		}
	}
	if (pairLevel > 1)
		sortPairs(cont);
	if ((cont.size() == 2 && cont[(cont.size() - 1)].size() != curElemSize) ||
		cont.size() == 1)
		return;
	curElemSize *= PAIR;
	// printContainer(cont, "Making the pairs");
	makePairs(cont);
}

/* ************************************************************************** */
/*                               DEBUG                                        */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::printContainer(
	const Container< Container< int, std::allocator< int > > > &cont,
	std::string contName)
{
	size_t i = 0;
	size_t j = 0;

	for (; i < cont.size(); ++i) {
		j = 0;
		std::cout << std::setw(30) << std::left << contName << "["
				  << std::setw(3) << i << "]	";
		for (; j < cont[i].size(); ++j) {
			std::cout << std::setw(3) << cont[i][j] << " ";
			if (cont[i].size() == curElemSize && j == (cont[i].size() / 2) - 1)
				std::cout << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "---" << std::endl;
}

/* ************************************************************************** */
/*                               PARSING                                      */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::addValidValue(const int64_t n,
											 const char *endptr)
{
	container.resize(container.size() + 1);
	if (*endptr && *endptr != ' ')
		throw forbiddenToken();
	if (n < 0 || n > UINT32_MAX) {
		std::cerr << n << ": ";
		throw outOfRange();
	}
	container[container.size() - 1].push_back(n);
}

/* ************************************************************************** */
/*                               UTILS                                        */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::sortPairs(
	Container< Container< int, std::allocator< int > > > &cont)
{
	for (size_t i = 0; i < cont.size() - 1; i += 2) {
		if (cont[i].size() == curElemSize &&
			cont[i + 1].size() == curElemSize) {
			if (cont[i].back() > cont[i + 1].back())
				std::swap(cont[i], cont[i + 1]);
		}
	}
}

template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::sort()
{
	makePairs(container);
	merge(container);
}
template <
	template < typename, typename = std::allocator< int > > class Container >
void MergeInsert< Container >::merge(
	Container< Container< int, std::allocator< int > > > &cont)
{
	while (cont.size() < iSize) {
		aIndex.reset();
		fillMain(cont);
	}
}

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< int > > class Container >
const char *MergeInsert< Container >::forbiddenToken::what() const throw()
{
	return "Forbidden token in input";
}
template <
	template < typename, typename = std::allocator< int > > class Container >
const char *MergeInsert< Container >::outOfRange::what() const throw()
{
	return "Value is outside expected range (uint32) [0 - 4294967295]";
}

template <
	template < typename, typename = std::allocator< int > > class Container >
const char *MergeInsert< Container >::singleValue::what() const throw()
{
	return "Single value cannot be sorted";
}