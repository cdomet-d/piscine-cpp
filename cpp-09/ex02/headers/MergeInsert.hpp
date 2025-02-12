/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:34:29 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERT_HPP
#define MERGEINSERT_HPP

#include "Jacobsthal.hpp"
#include "SisterTracker.hpp"
#include "Timer.hpp"

#include <string>

#define PAIR 2

template < template < class, class = std::allocator< uint32_t > > class Cont >

class MergeInsert {
  public:
	typedef Cont< uint32_t, std::allocator< uint32_t > > InnerCont;
	typedef Cont< InnerCont > OuterCont;

	/*                               ORTHODOX CLASS                           */
	MergeInsert(char **seq);
	MergeInsert(const MergeInsert &rhs);
	MergeInsert &operator=(const MergeInsert &rhs);
	~MergeInsert(void);

	/*                               METHODS                                  */
	void sort(const std::string &contType);

  private:
	/*                               METHODS                                  */
	// display
	void display(const bool showTime, const std::string &type) const;
	void printCont(const OuterCont &cont, const std::string &contName) const;
	void printInnerCont(const InnerCont &iCont) const;

	// parsing
	void addValidValue(const int64_t n, const char *endptr);

	// sorting
	InnerCont getStragglerElem();
	void binarySearch(size_t maxRange, OuterCont &main,
					  const InnerCont &toInsert);
	void defaultInsertion(size_t i, OuterCont &main, OuterCont &pend);
	void jacobsthalInsertion(OuterCont &main, OuterCont &pend);
	void makePairs(OuterCont &cont);
	void splitSort(OuterCont &cont);
	void undoPairs(OuterCont &cont);
	bool isPairInCont(const OuterCont &cont, const size_t &index) const;

	//helpers
	bool isSorted(typename OuterCont::const_iterator begin,
				  typename OuterCont::const_iterator end) const;
	void mergeElems(OuterCont &cont, size_t index);
	void sortElems(OuterCont &cont);
	void unmergeElems(OuterCont &cont,
					  const typename InnerCont::iterator &begin,
					  const typename InnerCont::iterator &end);

	/*                               GETTERS                                  */
	size_t getLast(const OuterCont &cont) const;

	/*                               MEMBERS                                  */
	// containers
	InnerCont straggler;
	OuterCont inputHolder;

	// Jacobstal numbers
	Jacobsthal jacobsthal;

	// trackers
	bool hasStraggler;
	const Timer clock;
	SisterTracker aIndex;
	uint32_t elemSize;
	uint32_t inputSize;

	/*                               PRIVATE CONSTRUCTORS                     */
	MergeInsert(void);
};

#include "MergeInsert.tpp"

#endif
