/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:48:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/13 02:12:16 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &src);
    ~Brain();
    
    Brain &operator=(const Brain &rhs);
    
    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};

#endif