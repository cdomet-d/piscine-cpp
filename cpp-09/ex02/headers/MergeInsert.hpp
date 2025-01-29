/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:40:58 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/29 13:56:08 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGEINSERT_HPP
#define MERGEINSERT_HPP

#include "Timer.hpp"
#include <vector>
#include <cstdlib>
#include <stdint.h>
#include <string>

#define PAIR 2

template < template < class, class = std::allocator< int > > class Container >

class MergeInsert {
  public:
	/*                               ORTHODOX CLASS                           */
	MergeInsert(void);
	MergeInsert(const std::string &seq);
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
	
	// debug
	void printContainer(
		const Container< Container< int, std::allocator< int > > > &cont, std::string contName);
	
	// parsing
	void addValidValue(const int64_t n, const char *endptr);
	
	// sorting
	void makePairs(Container< Container< int, std::allocator< int > > > &cont);
	void sortPairs(Container< Container< int, std::allocator< int > > > &cont);
	void splitPairs(Container< Container< int, std::allocator< int > > > &cont);
	void fillMain(Container< Container< int, std::allocator< int > > > &cont);
	bool makeElemFromStraggler(Container< Container< int, std::allocator< int > > > &cont);
	void merge(Container< Container< int, std::allocator< int > > > &cont);
	void sort();


  private:
	Container< Container< int, std::allocator< int > > > container;
	std::vector<int> sisterIndex;
	uint32_t iSize;
	uint32_t curElemSize;
	bool hasStraggler;
	Timer clock;
};

#include "MergeInsert.tpp"

#endif
