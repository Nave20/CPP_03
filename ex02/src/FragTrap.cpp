/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   GitHub : @Nave20                                  #+#    #+#             */
/*   28 is the new 42                                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "Frag Constructor called" << std::endl;
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Frag Constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "Frag Copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Frag Destructor called" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is out of energy !" << std::endl;
		return;
	}
	this->_energyPoints--;
	if (this->_hitPoints + amount >= 100)
	{
		std::cout << this->_name << " is back to it's prime !" << std::endl;
		this->_hitPoints = 100;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " is back to "<< this->_hitPoints << " HP !" << std::endl;
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << this->_name << " wants to do a Highfives !" << std::endl;
}
