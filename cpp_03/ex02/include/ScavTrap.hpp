/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:17:45 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/07 21:18:00 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    bool _guardMode;

public:
    // Constructeurs et destructeur
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();

    // Opérateur d'affectation
    ScavTrap& operator=(const ScavTrap& other);

    // Méthodes spécifiques à ScavTrap
    void attack(const std::string& target);
    void guardGate();
};

#endif