/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:29:45 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/11 01:48:46 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Constructors and destructor
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    // Assignment operator
    FragTrap& operator=(const FragTrap& other);

    // Specific method
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif