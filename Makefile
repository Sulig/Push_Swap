# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 17:07:32 by sadoming          #+#    #+#              #
#    Updated: 2023/11/29 14:31:22 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

DEF = 3 4 2 5 9

DEF = 89	40	13	77	54	28	88	84	30	61	51	18	11	32	80	8	42	9	16	93	71	26	7	73	4	65	29	76	27	46	50	15	53	47	22	31	20	72	43	60	92	99	67	56	17	57	66	70	81	98	62	41	58	83	5	23	1	64	2	19	33	90	79	59	24	100	21	6	25	78	55	12	63	86	44	3	85	82	39	95	68	35	14	45	69	87	96	97	91	34	48	75	10	38	74	49	94	36	52	37

#DEF = 54 433 9 413 208 315 302 289 124 82 56 354 81 362 264 428 271 449 439 46 22 16 254 398 359 30 383 92 401 407 317 405 27 142 434 244 89 98 139 218 229 272 231 263 20 38 285 471 400 371 141 24 320 23 499 64 333 447 35 67 319 246 386 446 452 164 31 72 192 458 437 283 312 473 132 261 12 129 190 53 200 252 291 262 461 243 399 238 427 112 430 79 296 14 233 332 226 49 443 219 34 237 223 15 66 298 327 236 366 342 48 10 170 217 37 134 250 111 328 416 424 40 374 234 288 409 488 255 476 196 474 396 293 230 415 489 365 74 101 256 275 465 343 438 492 0 62 189 90 389 303 195 274 370 292 136 5 375 422 155 419 166 493 50 421 494 418 125 127 18 353 85 123 259 137 442 459 322 144 41 412 188 157 71 466 329 270 299 337 361 104 287 21 180 113 269 106 211 364 352 391 469 286 197 368 105 496 425 183 108 36 207 455 265 477 436 468 2 460 294 214 369 281 278 221 44 378 107 163 497 351 326 372 8 253 167 344 43 331 260 440 121 340 376 220 168 472 307 397 435 360 267 122 115 295 334 29 429 240 172 94 314 235 305 277 484 381 84 213 65 462 388 348 17 119 284 169 215 185 308 324 133 485 140 60 408 176 143 423 478 159 93 88 73 224 3 193 349 245 80 480 201 212 377 109 451 500 232 51 309 130 184 251 282 482 59 178 75 61 454 335 161 380 116 385 110 100 120 174 402 406 316 394 87 171 209 339 182 228 114 445 495 33 257 162 321 426 346 450 97 227 431 68 42 266 304 158 403 241 117 186 363 181 347 203 78 102 99 379 179 239 126 325 483 420 11 358 76 268 225 152 91 276 338 491 411 393 306 4 355 63 318 7 199 128 153 118 138 150 382 131 392 222 301 417 96 86 457 248 323 367 432 356 486 52 57 249 210 216 39 463 313 350 45 6 258 311 453 69 273 160 95 444 103 280 32 341 55 154 1 145 357 498 187 191 310 414 464 395 456 147 70 205 384 475 165 387 25 336 373 242 470 19 198 175 479 297 290 151 156 404 410 146 13 441 135 490 279 390 177 77 47 148 83 448 247 300 481 58 173 202 330 194 204 467 26 206 487 149 345 28
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
