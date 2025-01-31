/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/31 15:13:10 by cdomet-d         ###   ########.fr       */
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
/*                               METHODS                                      */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::binarySearch(
	size_t maxRange, Cont< Cont< int, std::allocator< int > > > &main,
	Cont< int > &toInsert)
{
	std::vector< int > maxes;
	size_t last = toInsert.size() - 1;
	for (size_t i = 0; i < maxRange; ++i)
		maxes.push_back(main[i][last]);
	std::vector< int >::iterator insertionIt = std::lower_bound(
		maxes.begin(), maxes.begin() + maxRange, toInsert[last]);
	size_t insIndex = std::distance(maxes.begin(), insertionIt);
	std::cout << "Inserted at: " << insIndex << std::endl;
	main.insert(main.begin() + insIndex, toInsert);
	aIndex.update(insIndex);
}

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::fillMain(
	Cont< Cont< int, std::allocator< int > > > &cont)
{
	splitPairs(cont);
	hasStraggler = (cont[cont.size() - 1].size() != curElemSize);
	Cont< Cont< int, std::allocator< int > > > main;

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
	printContainer(cont, "Cont");
	for (size_t i = 2; (i < cont.size() && (cont[i].size() == curElemSize));
		 ++i) {
		if (!(i % 2)) {
			std::cout << "sorting cont[" << i << "]:";
			printInnerCont(cont[i]);
			std::cout << "should be paired with:";
			printInnerCont(main[aIndex.getMaxRange(i)]);
			binarySearch(aIndex.getMaxRange(i), main, cont[i]);
		}
	}
	while (hasStraggler && cont[(cont.size() - 1)].size() >= curElemSize) {
		Cont< int > stragglerElem =
			halfElemInStraggler(cont[(cont.size() - 1)]);
		if (stragglerElem.size() == curElemSize)
			binarySearch(main.size(), main, stragglerElem);
		main.push_back(cont[(cont.size() - 1)]);
	}
	container = main;
	printContainer(container, "Cont, exiting sort");
}

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::splitPairs(
	Cont< Cont< int, std::allocator< int > > > &cont)
{
	hasStraggler = (cont[cont.size() - 1].size() != curElemSize);

	Cont< Cont< int, std::allocator< int > > > splitPairs;

	size_t j = 0;
	curElemSize /= PAIR;
	for (size_t i = 0; cont[j].size() == (curElemSize * 2); ++i) {
		if (i % 2) {
			Cont< int > newPair((cont[j].begin() + (curElemSize)),
								cont[j].end());
			splitPairs.push_back(newPair);
		} else {
			Cont< int > newPair(cont[j].begin(),
								(cont[j].begin() + (curElemSize)));
			splitPairs.push_back(newPair);
		}
		j += (i % 2);
	}
	if (hasStraggler) {
		Cont< int > straggler(cont[(cont.size() - 1)].begin(),
							  cont[(cont.size() - 1)].end());
		splitPairs.push_back(straggler);
	}
	cont = splitPairs;
	// printContainer(cont, "this->cont, exiting splitPairs");
}

template < template < typename, typename = std::allocator< int > > class Cont >
Cont< int > MergeInsert< Cont >::halfElemInStraggler(Cont< int > &straggler)
{
	if (straggler.size() >= curElemSize) {
		Cont< int > elemFromStraggler(straggler.begin(),
									  straggler.begin() + curElemSize);
		straggler.erase(straggler.begin(), straggler.begin() + curElemSize);
		std::cout << "Got element from straggler: ";
		printInnerCont(elemFromStraggler);
		return elemFromStraggler;
	}
	return straggler;
}

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::makePairs(
	Cont< Cont< int, std::allocator< int > > > &cont)
{
	size_t i = 0;
	size_t pairLevel = cont.size() / PAIR;

	if (curElemSize > 1) {
		while (i < pairLevel && (cont.size() - i >= PAIR)) {
			cont[i].insert(cont[i].end(), cont[i + 1].begin(),
						   cont[i + 1].end());
			cont.erase(cont.begin() + i + 1);
			i++;
			// printContainer(cont, "MakePairs::formingPairs");
		}
		size_t last = cont.size() - 1;
		if (cont.size() > 1 && cont[last - 1].size() < curElemSize) {
			cont[last - 1].insert(cont[last - 1].end(), cont[last].begin(),
								  cont[last].end());
			cont.erase(cont.begin() + last);
			// printContainer(cont, "MakePairs::reattachingStraggler");
		}
	}
	if (pairLevel > 1)
		sortPairs(cont);
	if ((cont.size() == 2 && cont[(cont.size() - 1)].size() != curElemSize) ||
		cont.size() == 1)
		return;
	curElemSize *= PAIR;
	// printContainer(cont, "Done making the pairs");
	makePairs(cont);
}

/* ************************************************************************** */
/*                               DEBUG                                        */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::printContainer(
	const Cont< Cont< int, std::allocator< int > > > &cont,
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

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::addValidValue(const int64_t n, const char *endptr)
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

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::sortPairs(
	Cont< Cont< int, std::allocator< int > > > &cont)
{
	for (size_t i = 0; i < cont.size() - 1; i += 2) {
		if (cont[i].size() == curElemSize &&
			cont[i + 1].size() == curElemSize) {
			if (cont[i].back() > cont[i + 1].back())
				std::swap(cont[i], cont[i + 1]);
		}
	}
}

template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::sort()
{
	makePairs(container);
	merge(container);
}
template < template < typename, typename = std::allocator< int > > class Cont >
void MergeInsert< Cont >::merge(
	Cont< Cont< int, std::allocator< int > > > &cont)
{
	while (cont.size() < iSize) {
		aIndex.reset();
		fillMain(cont);
	}
}

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > > class Cont >
const char *MergeInsert< Cont >::forbiddenToken::what() const throw()
{
	return "Forbidden token in input";
}
template < template < typename, typename = std::allocator< int > > class Cont >
const char *MergeInsert< Cont >::outOfRange::what() const throw()
{
	return "Value is outside expected range (uint32) [0 - 4294967295]";
}

template < template < typename, typename = std::allocator< int > > class Cont >
const char *MergeInsert< Cont >::singleValue::what() const throw()
{
	return "Single value cannot be sorted";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template < template < typename, typename = std::allocator< int > > class Cont >
MergeInsert< Cont >::MergeInsert()
{
}

template < template < typename, typename = std::allocator< int > > class Cont >
MergeInsert< Cont >::MergeInsert(const std::string &seq) : curElemSize(1)
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

template < template < typename, typename = std::allocator< int > > class Cont >
MergeInsert< Cont >::~MergeInsert(void)
{
}