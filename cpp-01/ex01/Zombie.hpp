/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:40:43 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/05/02 15:45:13 by cdomet-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
  private:
	std::string _name;
	std::size_t it;

  public:
	Zombie(void);
	~Zombie(void);
	void nameZombie(std::size_t i, std::string name);
	void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
