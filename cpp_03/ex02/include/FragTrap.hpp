/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:29:45 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/10 19:15:16 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Constructeurs et destructeur
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    // Opérateur d'affectation
    FragTrap& operator=(const FragTrap& other);

    // Méthodes spécifiques à FragTrap
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif