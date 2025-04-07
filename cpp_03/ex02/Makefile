# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 21:01:35 by ayarmaya          #+#    #+#              #
#    Updated: 2025/04/07 21:32:19 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= fragtrap

CC					:= c++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98
RM					:= rm -f
RMDIR				:= rm -rf

HEADERS				:= -I./include

SRCDIR				:= src
SRCS				:= $(SRCDIR)/main.cpp \
					   $(SRCDIR)/ClapTrap.cpp \
					   $(SRCDIR)/ScavTrap.cpp \
					    $(SRCDIR)/FragTrap.cpp

OBJDIR				:= obj
OBJS				:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all					: $(NAME)

$(NAME)				: $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o		: $(SRCDIR)/%.cpp
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
		$(RMDIR) $(OBJDIR)

fclean				: clean
		$(RM) $(NAME)

re					: fclean all

.PHONY				: all clean fclean re