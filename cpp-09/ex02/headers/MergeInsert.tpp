/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:41:09 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/06 14:20:14 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MergeInsert.hpp"
#include "cerrno"
#include <algorithm>
#include <iomanip>
#include <iostream>

#define INVALID "\033[38;5;206m"
#define VALID "\033[0;32m"
#define RESET "\033[0m"

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::binarySearch(size_t maxRange, OuterCont &main,
									   const InnerCont &toInsert)
{
	if (main.empty() || toInsert.empty())
		return;
	std::vector< int > maxes;
	maxes.reserve(maxRange + 1);

	for (size_t i = 0; (i < (main.size()) && i < maxRange); ++i)
		maxes.push_back(main.at(i).back());
	std::vector< int >::iterator insIt =
		std::lower_bound(maxes.begin(), maxes.end(), toInsert.back());
	size_t insIndex = insIt - maxes.begin();
	main.insert(main.begin() + insIndex, toInsert);
	aIndex.update(insIndex);
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::jacobsthalInsertion(OuterCont &main, OuterCont &pend)
{
	jacobsthal.update();
	// std::cout << "Jake Insert" << std::endl;
	size_t elems = 0;
	int64_t curJ = jacobsthal.getI() - 2;
	int64_t prevJ = (curJ == 1) ? 0 : jacobsthal.getPrevI() - 2;
	// std::cout << "curj: " << curJ << " | prevJ: " << prevJ << std::endl;
	if (prevJ == 0) {
		for (; curJ >= 0; --curJ) {
			// std::cout << "pend.at(curJ)" << std::endl;
			// printInnerCont(pend.at(curJ));
			// std::cout << std::endl;
			// std::cout << "main.at(aIndex.getMaxRange(curJ))" << std::endl;
			// printInnerCont(main.at(aIndex.getMaxRange(curJ)));
			// std::cout << std::endl;
			binarySearch(aIndex.getMaxRange(curJ), main, pend.at(curJ));
			elems++;
		}
	} else {
		for (; curJ > prevJ; --curJ) {
			// std::cout << "pend.at(curJ)" << std::endl;
			// printInnerCont(pend.at(curJ));
			// std::cout << std::endl;
			// std::cout << "main.at(aIndex.getMaxRange(curJ))" << std::endl;
			// printInnerCont(main.at(aIndex.getMaxRange(curJ)));
			// std::cout << std::endl;
			binarySearch(aIndex.getMaxRange(curJ), main, pend.at(curJ));
			elems++;
		}
	}
	jacobsthal.setInsertedElems(elems);
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::defaultInsertion(size_t i, OuterCont &main,
										   OuterCont &pend)
{
	size_t elems = 0;
	// std::cout << "Default Insert" << std::endl;

	for (; i < pend.size(); ++i) {
		// std::cout << "pend.at(i)" << std::endl;
		// printInnerCont(pend.at(i));
		// std::cout << std::endl;
		// std::cout << "main.at(aIndex.getMaxRange(i))" << std::endl;
		// printInnerCont(main.at(aIndex.getMaxRange(i)));
		// std::cout << std::endl;
		binarySearch(aIndex.getMaxRange(i), main, pend.at(i));
		elems++;
	}
	jacobsthal.setInsertedElems(elems);
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::splitSort(OuterCont &cont)
{
	undoPairs(cont);
	OuterCont main;
	OuterCont pend;

	aIndex.reset();
	aIndex.init(main.size());
	size_t j = 2;
	for (size_t i = 0; isPairInCont(cont, i); ++i) {
		if (i % 2 || i == 0) {
			main.push_back(cont.at(i));
			if (i > 1)
				aIndex.add(j++);
		} else
			pend.push_back(cont.at(i));
	}
	// printCont(cont, "cont");
	for (size_t i = 0; i < pend.size(); i += jacobsthal.getInsertedElems()) {
		if (jacobsthal.isNeeded(pend.size(), i)) {
			jacobsthalInsertion(main, pend);
		} else {
			defaultInsertion(i, main, pend);
		}
	}
	while (!straggler.empty() && straggler.size() >= elemSize) {
		InnerCont stragglerElem = getStragglerElem();
		if (stragglerElem.size() == elemSize)
			binarySearch(main.size(), main, stragglerElem);
	}
	// printCont(main, "main");
	std::cout << (isSorted(main.begin(), main.end())
					  ? "Input is successfully sorted"
					  : "Input is not sorted")
			  << std::endl;
	cont = main;
	jacobsthal.reset();
	if (cont.size() == inputSize)
		return;
	splitSort(cont);
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::undoPairs(OuterCont &cont)
{
	hasStraggler = (cont.at(getLast(cont)).size() != elemSize);
	if (cont.size() > 1 && hasStraggler) {
		straggler = cont.at(getLast(cont));
		cont.pop_back();
	}

	OuterCont splitPairs;
	elemSize /= PAIR;
	size_t contIndex = 0;
	for (size_t pairIndex = 0; (contIndex < cont.size() &&
								cont.at(contIndex).size() == (elemSize * 2));
		 ++pairIndex) {
		if (pairIndex % 2)
			unmergeElems(splitPairs, cont.at(contIndex).begin() + elemSize,
						 cont.at(contIndex).end());
		else
			unmergeElems(splitPairs, cont.at(contIndex).begin(),
						 cont.at(contIndex).begin() + elemSize);
		contIndex += (pairIndex % 2);
	}
	cont = splitPairs;
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
typename MergeInsert< Cont >::InnerCont MergeInsert< Cont >::getStragglerElem()
{
	if (straggler.size() >= elemSize) {
		InnerCont elemFromStraggler(straggler.begin(),
									straggler.begin() + elemSize);
		straggler.erase(straggler.begin(), straggler.begin() + elemSize);
		return elemFromStraggler;
	}
	return straggler;
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::makePairs(OuterCont &cont)
{
	const size_t pairLevel = cont.size() / PAIR;

	if (elemSize > 1) {
		for (size_t curPairI = 0;
			 curPairI < pairLevel && (cont.size() - curPairI >= PAIR);
			 ++curPairI) {
			mergeElems(cont, curPairI);
		}
		size_t last = getLast(cont);
		if (cont.size() > 1 && cont.at(last - 1).size() < elemSize) {
			mergeElems(cont, last);
		}
	}
	sortElems(cont);
	if ((cont.size() == 2 && cont.at(getLast(cont)).size() != elemSize) ||
		cont.size() == 1)
		return;
	elemSize *= PAIR;
	makePairs(cont);
}

/* ************************************************************************** */
/*                               HELPERS                                      */
/* ************************************************************************** */
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::sortElems(OuterCont &cont)
{
	for (size_t i = 0; i < cont.size() - 1; i += 2) {
		if (cont.at(i).size() == elemSize &&
			cont.at(i + 1).size() == elemSize) {
			if (cont.at(i).back() > cont.at(i + 1).back())
				std::swap(cont.at(i), cont.at(i + 1));
		}
	}
}
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::mergeElems(OuterCont &cont, const size_t index)
{
	cont.at(index).insert(cont.at(index).end(), cont.at(index + 1).begin(),
						  cont.at(index + 1).end());
	cont.erase(cont.begin() + (index + 1));
}
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::unmergeElems(
	OuterCont &cont, const typename InnerCont::iterator &begin,
	const typename InnerCont::iterator &end)
{
	InnerCont newPair(begin, end);
	cont.push_back(newPair);
}
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
bool MergeInsert< Cont >::isPairInCont(const OuterCont &cont,
									   const size_t &index) const
{
	return (index < cont.size() && (cont.at(index).size() == elemSize));
}
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
bool MergeInsert< Cont >::isSorted(typename OuterCont::const_iterator begin,
								   typename OuterCont::const_iterator end) const
{
	typename OuterCont::const_iterator next = begin;
	++next;
	for (; next != end; ++begin, ++next) {
		if ((*begin).back() > (*next).back()) {
			std::cout << (*begin).back() << " is greater than "
					  << (*next).back() << std::endl;
			return false;
		}
	}
	return true;
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
size_t MergeInsert< Cont >::getLast(const OuterCont &cont) const
{
	return cont.size() - 1;
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::sort(const std::string &contType)
{
	std::cout << std::setw(22) << std::left << INVALID "Before" RESET;
	display(false, contType);
	makePairs(inputHolder);
	splitSort(inputHolder);
	std::cout << std::setw(22) << std::left << INVALID "After" RESET;
	display(true, contType);
}

/* ************************************************************************** */
/*                               PARSING                                      */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::addValidValue(const int64_t n, const char *endptr)
{
	if (*endptr && *endptr != ' ') {
		std::cout << *endptr << std::endl;
		throw forbiddenToken();
	}
	if (n < 0 || n > UINT32_MAX) {
		std::cerr << n << ": ";
		throw outOfRange();
	}
	InnerCont newElem(1, n);
	inputHolder.push_back(newElem);
}

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
const char *MergeInsert< Cont >::forbiddenToken::what() const throw()
{
	return "Forbidden token in input";
}
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
const char *MergeInsert< Cont >::outOfRange::what() const throw()
{
	return "Value is outside expected range (uint32) [0 - 4294967295]";
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
const char *MergeInsert< Cont >::singleValue::what() const throw()
{
	return "Single value cannot be sorted";
}

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
MergeInsert< Cont >::MergeInsert() : elemSize(1)
{
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
MergeInsert< Cont >::MergeInsert(char **seq) : hasStraggler(false), elemSize(1)
{
	char *endptr = NULL;
	for (size_t i = 0; seq[i]; ++i) {
		uint64_t val = std::strtod(seq[i], &endptr);
		addValidValue(val, endptr);
	}
	inputSize = inputHolder.size();
	if (inputSize <= 1)
		throw singleValue();
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
MergeInsert< Cont >::~MergeInsert(void)
{
}

/* ************************************************************************** */
/*                               DISPLAY                                      */
/* ************************************************************************** */

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::display(const bool showTime,
								  const std::string &type) const
{
	std::cout << "using std::" + type + ": ";
	for (size_t i = 0; i < inputHolder.size(); ++i) {
		printInnerCont(inputHolder.at(i));
	}
	if (showTime) {
		std::cout << std::endl
				  << "Time to process a range of " << inputSize << std::setw(20)
				  << std::left << " using std::" + type;
		clock.displayTimeElasped();
		std::cout << (isSorted(inputHolder.begin(), inputHolder.end())
						  ? VALID "Input is successfully sorted" RESET
						  : INVALID "Input is not sorted" RESET)
				  << std::endl;
	}
	std::cout << std::endl;
}

template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::printInnerCont(const InnerCont &iCont) const
{
	if (iCont.empty())
		return;
	for (typename InnerCont::const_iterator it = iCont.begin();
		 it != iCont.end(); ++it)
		std::cout << *it << " ";
}
template <
	template < typename, typename = std::allocator< uint32_t > > class Cont >
void MergeInsert< Cont >::printCont(const OuterCont &cont,
									const std::string &contName) const
{
	size_t i = 0;
	size_t j = 0;

	for (; i < cont.size(); ++i) {
		j = 0;
		std::cout << std::setw(30) << std::left << contName << "["
				  << std::setw(3) << i << "]	";
		for (; j < cont.at(i).size(); ++j) {
			std::cout << std::setw(3) << cont.at(i).at(j) << " ";
			if (cont.at(i).size() == elemSize &&
				j == (cont.at(i).size() / 2) - 1)
				std::cout << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "---" << std::endl;
}