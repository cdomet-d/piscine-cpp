/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Timer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 09:56:53 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/06 16:32:30 by cdomet-d         ###   ########.fr       */
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

	/*                               PRIVATE CONSTRUCTORS                     */
	Timer(const Timer &copy);
	Timer &operator=(const Timer &copy);
};

#endif
