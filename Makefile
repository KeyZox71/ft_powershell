# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjoly <adjoly@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 10:49:52 by adjoly            #+#    #+#              #
#    Updated: 2024/04/25 10:59:23 by adjoly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

OBJSDIR = obj/

SRC = $(shell find src -name '*.c')

I_DIR = include/

LIBFT_DIR = libft/
	   
INCLUDE = -I $(I_DIR) -I $(LIBFT_DIR) 

OBJS = $(addprefix $(OBJSDIR), $(SRC:.c=.o))

FLAGS = -Werror -Wall -Wextra -g

LIB = libft/libft.a \

$(NAME): $(OBJS)
	@make -s -C libft
	@$(CC) $(FLAGS) -lreadline $(OBJS) $(LIB) -o $(NAME)
	@echo "[✔] Compiled"

$(OBJSDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(INCLUDE) $(FLAGS) $< -c -o $@
	@echo "[✔] $< compiled"

all: $(NAME)

clean:
	@make -s -C libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)
	@rm -Rf $(OBJSDIR)
	@echo "[X] Cleaned"

re: fclean all

.PHONY: clean all re fclean