/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:43 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/02/05 12:36:13 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// First, implement a Zombie class. It has a string private attribute name.
// Add a member function void announce( void ); to the Zombie class. Zombies
// announce themselves as follows:
// <name>: BraiiiiiiinnnzzzZ...

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(std::string _name);
	~Zombie(void);
	void	announce(void);
};

Zombie*	newZombie( std::string _name );
void	randomChump( std::string _name );

#endif
