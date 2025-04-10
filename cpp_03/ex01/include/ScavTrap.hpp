/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:17:45 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 18:06:49 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
    bool _guardMode;

public:
    // Constructor and destructor
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();

    // Assigment operator
    ScavTrap& operator=(const ScavTrap& other);

    // ScavTrap specific method
    void attack(const std::string& target);
    void guardGate();
};

#endif