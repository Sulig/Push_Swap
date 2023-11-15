# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/11/15 20:23:03 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DEF = 2 1 4 3
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:

DIR = ./src
LIBFT = ./Libft
# ------------------- #
# Sorces:

MAK = Makefile

ARL = $(LIBFT)/libft.a

LIB = push_swap.h
SRC = push_swap_main ft_check_errors ft_print_stat ft_push ft_reverse ft_rotate\
	  ft_swap ft_utils ft_layton ft_sort_four ft_sort_in_one

OBJ = $(addprefix $(DIR)/, $(addsuffix .o, $(SRC)))
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ all  \t\t #-> Make $(NAME)\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ trueall \t #-> Make norm + make all + make run\n"
	@echo "\t~ run  \t\t #-> Run $(NAME) with $(DEF)\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME)\n"
	@echo "\t~ re_trueall \t #-> Redo & make trueall\n"
	@echo "\n~ Extra comands:\n"
	@echo "\t~ debug \t #-> Ejecutes lldb $(NAME) $(DEF)\n"
	@echo "\t~ leaks \t #-> Ejecutes leaks $(NAME) $(DEF)\n"
	@echo "\t~ val  \t\t #-> Run Valgrind $(NAME) $(DEF)\n"
	@make -s author

#-------------------------------------------------------------#
#-------------------------------------------------------------#
author:
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo "\n   ~ \t      Made by Sadoming \t        ~\n"
	@echo "\n~ **************************************** ~\n\n"
#-------------------------------------------------------------#
#-------------------------------------------------------------#
trueall:
	@make -s norm
	@echo "\033[0;37m\n~ **************************************** ~\n"
	@make -s $(NAME)
	@make -s run

#-------------------------------------------------------------#
norm:
	@make -s norm -C $(LIBFT)
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(DIR)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette -R CheckForbiddenSourceHeader $(DIR)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK"

#-------------------------------------------------------------#
#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~ \033[1;37m\n"
	@./$(NAME) $(DEF)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

$(ARL):
	@echo "\033[1;93m\n * Compiling Libft -->\033[1;97m\n"
	@make -s -C $(LIBFT)
	@echo "\033[1;37m\n~ **************************************** ~\n"

$(DIR)/%.o: $(DIR)/%.c $(DIR)/$(LIB) $(MAK)
	$(CC) $(CFLAGS) -c $< -o $@

#-------------------------------------------------------------#
$(NAME): $(MAK) $(ARL) $(OBJ)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(NAME) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJ) -o $(NAME)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t    Push_Swap is ready!\t         ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
# ******************************************************************************* #
# Debuging region:

debug: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(NAME) $(DEF)
# ------------------

leaks: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(NAME) $(DEF)
# ------------------

val: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@valgrind ./$(NAME) $(DEF)

# ********************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(OBJ)
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
re_trueall: clear trueall
# -------------------- #
.PHONY: all bonus clean clear fclean debug leaks norm re run val trueall
.PHONY: re_trueall
# ********************************************************************************** #
