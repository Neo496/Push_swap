# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atouba <atouba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 18:18:34 by atouba            #+#    #+#              #
#    Updated: 2022/03/12 17:09:27 by atouba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMES_BONUS = push_swap_bonus

CC = gcc -Wall -Wextra -Werror

FILES = push_swap.c ft_check.c lis.c lis_utils_one.c lis_utils_two.c \
		actions.c ft_tools.c \
		push_back_a.c push_back_a_utils.c \

FILES_BONUS = push_swap_bonus.c ft_tools_bonus.c actions_bonus.c ft_check_bonus.c \
		ft_tools_one_bonus.c ft_tools_two_bonus.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c

all: $(NAME)

$(NAME):
	$(CC) $(FILES) -o $(NAME) 

bonus:
	$(CC) $(FILES_BONUS) -o $(NAMES_BONUS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) $(NAMES_BONUS)

re: fclean all

# define HEADER
#                   _                               
#                  | |                              
#   _ __  _   _ ___| |__    _____      ____ _ _ __  
#  | '_ \| | | / __| '_ \  / __\ \ /\ / / _` | '_ \ 
#  | |_) | |_| \__ \ | | | \__ \\ V  V / (_| | |_) |
#  | .__/ \__,_|___/_| |_| |___/ \_/\_/ \__,_| .__/ 
#  | |                                       | |    
#  |_|                                       |_|    

# endef
# export HEADER

# header:
# 	@echo "$$HEADER"