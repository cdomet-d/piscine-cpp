/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauseff <jauseff@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:47:26 by jauseff           #+#    #+#             */
/*   Updated: 2024/08/30 17:26:19 by jauseff          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

clapTrap::clapTrap(void) { }

clapTrap::clapTrap(std::string _name) { 
	this->name = _name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 10;
}

clapTrap::clapTrap(const clapTrap& copy) { 
	clapTrap(copy.name);
}

clapTrap::~clapTrap(void) { }

clapTrap &clapTrap::operator=(const clapTrap& comp) {
	this->name = comp.name;
	this->hitPoints = comp.hitPoints;
	this->energyPoints = comp.energyPoints;
	this->attackDamage = comp.attackDamage;
}