# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 00:02:13 by ayarmaya          #+#    #+#              #
#    Updated: 2025/03/27 00:23:22 by ayarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= brain

CC					:= c++
CFLAGS				:= -Wall -Wextra -Werror -std=c++98
RM					:= rm -f
RMDIR				:= rm -rf

SRCDIR				:= src
SRCS				:= $(SRCDIR)/main.cpp

OBJDIR				:= obj
OBJS				:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

all					: $(NAME)

$(NAME)				: $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o		: $(SRCDIR)/%.cpp
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RMDIR) $(OBJDIR)

fclean				: clean
		$(RM) $(NAME)

re					: fclean all

.PHONY				: all clean fclean re