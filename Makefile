# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/11/07 17:48:10 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# ------------------ #
# Flags:

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I
# ------------------ #
# Directories:

DIR = ./src
DIRB = ./bonus

#TEST = ./Tests
LIBFT = ./Libft
# ------------------- #
# Sorces:

MAK = Makefile

ARL = $(LIBFT)/libft.a

LIB = #
SRC = #
#OBJ = $(addprefix $(DIR)/, $(addsuffix .o, $(SRC)))
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
	@echo "\t~ trueall \t #-> Make norm + make all\n"
	@echo "\t~ run  \t\t #-> Run so_long with $(MAP)\n"
	@echo "\t~ re   \t\t #-> Redo so_long\n"
	@echo "\t~ re_trueall \t #-> Redo & make trueall\n"
	@echo "\n~ Extra comands:\n"
	@echo "\t~ debug \t #-> Ejecutes lldb $(NAME) $(MAP)\n"
	@echo "\t~ leaks \t #-> Ejecutes leaks $(NAME) \n"
	@echo "\t~ val  \t\t #-> Run Valgrind $(NAME) \n"
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

#-------------------------------------------------------------#
norm:
	@make -s norm -C $(LIBFT)
	@echo "\n\033[1;93m~ Norminette:"
	@norminette $(DIR)
	@norminette -R CheckForbiddenSourceHeader $(DIR)
	@echo "\033[1;32m\n ~ Norminette:\t~ OK"

#-------------------------------------------------------------#
#-------------------------------------------------------------#
run: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) "
	@echo "\n~ **************************************** ~\n"
	@./$(NAME) 
#-------------------------------------------------------------#
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

$(ARL):
	@echo "\033[1;93m\n * Compiling Libft -->\033[1;97m\n"
	@make -s -C $(LIBFT)
	@echo "\033[1;37m\n~ **************************************** ~\n"

$(DIR)/%.o : $(DIR)/%.c ./src/$(LIB)
	$(CC) $(CFLAGS) -c $<

#-------------------------------------------------------------#
$(NAME): $(MAK) $(ARL) $(OBJ)
	@echo "\033[1;37m\n~ **************************************** ~\n"
	@echo "\033[1;93m * Making so_long -->\033[1;97m\n"
	@$(CC) $(ARL) $(OBJ) -L -o $(NAME)
	@echo "\033[1;35m\n~ **************************************** ~\n"
	@echo "  ~\t     Push_Swap is ready!\t\t ~\n"
	@echo "~ **************************************** ~\n"
#-------------------------------------------------------------#
# ******************************************************************************* #
# Debuging region:

debug: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) "
	@echo "\n~ **************************************** ~\n"
	@lldb $(NAME) 
# ------------------

leaks: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@leaks -atExit -- ./$(NAME) $(MAP)
# ------------------

val: $(NAME)
	@echo "\033[1;34m\n~ **************************************** ~\n"
	@echo " ~ Running ./$(NAME) $(MAP)"
	@echo "\n~ **************************************** ~\n"
	@valgrind ./$(NAME) $(MAP)

# ********************************************************************************* #
# Clean region

clean:
	@make -s clean -C $(LIBFT)
	@/bin/rm -f $(DIR)/*.o
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
