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

#include "../inc/ClapTrap.hpp"

#include <iostream>
#include <ostream>

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is out of energy !" << std::endl;
		return;
	}
	if (target == this->_name)
	{
		std::cout << this->_name << " can't attack himself !" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << this->_name << " attacks " << target << ", causing "<< this->_attackDamage << " points of damage !"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int damage)
{
	if (damage >= this->_hitPoints)
	{
		this->_hitPoints = 0;
		std::cout << this->_name << " is knocked out !"<< std::endl;
	}
	else
	{
		this->_hitPoints -= damage;
		std::cout << this->_name << " took " << damage << " points of damage !" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << this->_name << " is out of energy !" << std::endl;
		return;
	}
	this->_energyPoints--;
	if (this->_hitPoints + amount >= 10)
	{
		std::cout << this->_name << " is back to it's prime !" << std::endl;
		this->_hitPoints = 10;
	}
	else
	{
		this->_hitPoints += amount;
		std::cout << this->_name << " is back to "<< this->_hitPoints << " HP !" << std::endl;
	}
}

void ClapTrap::setEnergy(unsigned int energy) {this->_energyPoints = energy;}
