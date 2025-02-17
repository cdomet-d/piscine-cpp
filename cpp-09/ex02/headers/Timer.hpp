/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/17 13:12:02 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>

class Timer {
  public:
	/*                               ORTHODOX CLASS                           */
	Timer(void);
	~Timer(void);

	/*                               METHODS                                  */
	void displayTimeElasped() const;

	/*                               SETTERS                                  */
  private:
	std::clock_t start;
	Timer(const Timer &rhs);
	Timer &operator=(const Timer &rhs);

	/*                               PRIVATE CONSTRUCTORS                     */
};

#endif