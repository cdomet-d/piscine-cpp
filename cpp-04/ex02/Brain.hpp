/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:28:11 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:05 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
private:
	std::string ideas[100];
public:
	/*                               ORTHODOX CLASS                           */
	Brain(void);
	Brain(const Brain &rhs);
	~Brain(void);
	Brain &operator=(const Brain &rhs);

	/*                               METHODS                                  */
	void fillArr(std::string idea);
	void displayArr(void) const;

	/*                               GETTERS                                  */
	
	/*                               SETTERS                                  */
};

#endif
