/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/03 15:26:32 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERT_HPP
#define MERGEINSERT_HPP

#include "SisterTracker.hpp"
#include "Timer.hpp"
#include <cstdlib>
#include <stdint.h>
#include <string>
#include <vector>

#define PAIR 2

template < template < class, class = std::allocator< uint32_t > > class Cont >

class MergeInsert {
  public:
	typedef Cont< uint32_t, std::allocator< uint32_t > > InnerCont;
	typedef Cont< InnerCont > OuterCont;
	/*                               ORTHODOX CLASS                           */
	MergeInsert(char **seq);
	MergeInsert(const MergeInsert &copy);
	MergeInsert &operator=(const MergeInsert &copy);
	~MergeInsert(void);

	/*                               EXCEPTIONS                               */
	class outOfRange : public std::exception {
	  public:
		const char *what() const throw();
	};
	class forbiddenToken : public std::exception {
	  public:
		const char *what() const throw();
	};
	class singleValue : public std::exception {
	  public:
		const char *what() const throw();
	};

	/*                               METHODS                                  */
	void sort(const std::string &contType);

  private:
	/*                               METHODS                                  */
	// display
	void printCont(const OuterCont &cont, const std::string &contName) const;
	void printInnerCont(const InnerCont &iCont) const;
	void display(const bool showTime, const std::string &type) const;

	// parsing
	void addValidValue(const int64_t n, const char *endptr);

	// sorting
	InnerCont getStragglerElem();
	void binarySearch(size_t maxRange, OuterCont &main,
					  const InnerCont &toInsert);
	void splitSort(OuterCont &cont);
	void makePairs(OuterCont &cont);
	void undoPairs(OuterCont &cont);

	//helpers
	void sortElems(OuterCont &cont);
	void mergeElems(OuterCont &cont, size_t index);
	void unmergeElems(OuterCont &cont,
					  const typename InnerCont::iterator &begin,
					  const typename InnerCont::iterator &end);
	bool isPairInCont(const OuterCont &cont, const size_t &index) const;
	bool isSorted(typename OuterCont::const_iterator begin,
				  typename OuterCont::const_iterator end) const;

	/*                               GETTERS                                  */
	size_t getLast(const OuterCont &cont) const;

	/*                               MEMBERS                                  */
	// containers
	InnerCont straggler;
	OuterCont inputHolder;
	SisterTracker aIndex;
	const Timer clock;

	// trackers
	bool hasStraggler;
	uint32_t elemSize;
	uint32_t inputSize;

	MergeInsert(void);
};

#include "MergeInsert.tpp"

#endif
