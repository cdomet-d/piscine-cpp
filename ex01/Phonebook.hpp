/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:50:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/18 13:45:47 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

# define COLOR "\x1B[1;32m"
# define PINK "\x1B[1;31m"
# define END "\033[0m"

class Phonebook {
	private:
		Contact contact[8];
		int	nb_contact;

	public:
		Phonebook();
		void	addNew();
		void	displaySingle(size_t i);
		void	displaySearch();
		void 	displayIndex();
};

#endif