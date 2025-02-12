/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SisterTracker.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:23:27 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SISTERTRACKER_HPP
#define SISTERTRACKER_HPP

#include <stdint.h>
#include <vector>
#include <cstdlib>

class SisterTracker {
  public:
	/*                               ORTHODOX CLASS                           */
	SisterTracker(void);
	~SisterTracker(void);
	SisterTracker &operator=(const SisterTracker &rhs);

	/*                               METHODS                                  */
	void update(size_t insertionIndex);
	void print();

	/*                               GETTERS                                  */
	size_t getMaxRange(size_t bIndex) const;

	/*                               SETTER                                   */
	void init(size_t size);
	void add(size_t aIndex);
	void reset();


  private:
	std::vector< size_t > sisterIndex;
	
	/*                               PRIVATE CONSTRUCTORS                     */
	SisterTracker(const SisterTracker &rhs);
};

#endif
