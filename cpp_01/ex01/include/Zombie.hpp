/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 23:02:54 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/05 00:33:49 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie();
	~Zombie();
	
	void setName(std::string name);
	void announce(void) const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
