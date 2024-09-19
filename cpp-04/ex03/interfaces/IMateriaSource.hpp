/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:40:36 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/09/19 13:11:27 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include "AMateria.hpp"
class IMateriaSource
{
private:
	
public:
	/*                               ORTHODOX CLASS                           */
	IMateriaSource(void);
	IMateriaSource(const IMateriaSource &copy);
	virtual ~IMateriaSource(void);
	IMateriaSource &operator=(const IMateriaSource &copy);

	/*                               METHODS                                  */
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
