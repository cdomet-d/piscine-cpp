/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:21:52 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/06 16:57:52 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JACOBSTHAL_HPP
#define JACOBSTHAL_HPP

#include <cstddef>

class Jacobsthal {
  public:
	/*                               ORTHODOX CLASS                           */
	Jacobsthal(void);
	~Jacobsthal(void);

	/*                               METHODS                                  */
	bool isNeeded(size_t contLen, size_t pendIndex);
	void display();
	void update();
	void reset();
	/*                               GETTERS                                  */
	size_t getI() const;
	size_t getPrevI() const;
	size_t getNextI() const;
	size_t getInsertedElems() const;

	/*                               SETTERS                                  */
	void setInsertedElems(size_t  n);


  private:
	size_t currentJ;
	size_t previousJ;
	size_t nextJ;
	size_t insertedElems;

	// private constructors
	Jacobsthal(const Jacobsthal &copy);
	Jacobsthal &operator=(const Jacobsthal &copy);
};

#endif