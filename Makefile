# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/11/30 17:05:08 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

DEF = 3 4 2 5 9 10
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# ------------------ #
# Directories:

DIR = ./src
DIRB = ./bonus
LIBFT = ./Libft
# ------------------- #
# Sorces:

MAK = Makefile

ARL = $(LIBFT)/libft.a

LIB = push_swap.h
SRC = push_swap_main ft_check_errors ft_man_struct ft_push ft_reverse ft_rotate\
	  ft_swap ft_print_stat ft_utils ft_sort_in_one ft_sort_four ft_big_sort ft_layton\
	  ft_decide_to_push

LIBB = push_swap_bonus.h
SRCB = push_swap_main_bonus ft_check_errors_bonus ft_man_structs_bonus ft_push_bonus\
	   ft_reverse_bonus ft_rotate_bonus ft_swap_bonus ft_utils_bonus

OBJ = $(addprefix $(DIR)/, $(addsuffix .o, $(SRC)))
OBJB = $(addprefix $(DIRB)/, $(addsuffix .o, $(SRCB)))
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(NAME)

bonus: $(BONUS)
#-------------------------------------------------------------#
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ all  \t\t #-> Make $(NAME)\n"
	@echo "\t~ bonus \t #-> Make $(BONUS)\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ trueall \t #-> Make norm + make all + make run\n"
	@echo "\t~ run  \t\t #-> Run $(NAME) with $(DEF)\n"
	@echo "\t~ run_bonus \t #-> Run $(BONUS) with $(DEF)\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME)\n"
	@echo "\t~ re_bonus \t #-> Redo bonus\n"
	@echo "\t~ re_trueall \t #-> Redo & make trueall\n"
	@echo "\n~ Extra comands:\n"
	@echo "\t~ debug \t #-> Ejecutes lldb $(NAME) $(DEF)\n"
	@echo "\t~ debug_bonus \t #-> Ejecutes lldb $(BONUS) $(DEF)\n"
	@echo "\t~ leaks \t #-> Ejecutes leaks $(NAME) $(DEF)\n"
	@echo "\t~ leaks_bonus \t #-> Run $(BONUS) with LEAKS & $(DEF)\n"
	@echo "\t~ val  \t\t #-> Run Valgrind $(NAME) $(DEF)\n"
	@echo "\t~ val_bonus \t #-> Run valgrind $(BONUS) $(DEF)\n"
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
	@make -s run_bonus

#-------------------------------------------------------------#
norm:
	@make -s norm -C $(LIBFT)
	@echo "\n\033[1;93m~ Norminette:\n"
	@norminette $(DIR)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette -R CheckForbiddenSourceHeader $(DIR)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~\n"
	@echo "\n\033[1;93m\n~ Norminette bonus:\n"
	@norminette $(DIRB)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette -R CheckForbiddenSourceHeader $(DIRB)
	@echo "\033[1;32m\n ~ Norminette bonus:\t~ OK\n"

#-------------------------------------------------------------#
#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~ \033[1;37m\n"
	@./$(NAME) $(DEF)

#-------------------------------------------------------------#
run_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@./$(BONUS) $(DEF)

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
# Bonus:

$(DIRB)/%.o : $(DIRB)/%.c $(DIRB)/$(LIBB)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS): $(MAK) $(ARL) $(OBJB)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making $(BONUS) -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJB) -o $(BONUS)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t   Checker is ready!\t\t~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
# ******************************************************************************* #
# Debuging region:

debug: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(NAME) $(DEF)

debug_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@lldb $(BONUS) $(DEF)
# ------------------

leaks: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(NAME) $(DEF)

leaks_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(BONUS) $(DEF)
# ------------------

val: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@valgrind --leak-check=full -s ./$(NAME) $(DEF)

val_bonus: $(BONUS)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(BONUS) $(DEF)"
	@echo "\n~ **************************************** ~\n"
	@valgrind ./$(BONUS) $(DEF)

# ********************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(OBJB)
	@find . -name ".DS_Store" -type f -delete
	@echo "\033[1;34m\n All obj removed\033[1;97m\n"


fclean: clean
	@make -s fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(BONUS)
	@/bin/rm -frd $(NAME).dSYM
	@/bin/rm -frd $(BONUS).dSYM
	@echo "\033[1;34m All cleaned succesfully\033[1;97m\n"

clear: fclean
	@clear

re: fclean all
re_bonus: fclean bonus
re_trueall: clear trueall
# -------------------- #
.PHONY: all bonus clean clear fclean debug leaks norm re run val trueall
.PHONY: debug_bonus leaks_bonus re_bonus re_trueall val_bonus
# ********************************************************************************** #
