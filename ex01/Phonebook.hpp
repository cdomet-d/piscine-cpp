/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:50:13 by cdomet-d          #+#    #+#             */
/*   Updated: 2024/07/16 16:58:03 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class Phonebook {
	private:
		Contact contact[8];
		size_t	nb_contact;

	public:
		Phonebook();
		void	addNew();
		void	displaySingle(size_t i);
		void	displaySearch();
		void 	displayIndex();
};

#endif