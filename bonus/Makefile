##
## EPITECH PROJECT, 2023
## my_lib
## File description:
## my_lib
##

CC	=	gcc

NAME	=	mysh

UNIT_TEST	= test

CFLAGS	=	-g -Wshadow -Werror -Wall -I./include -lncurses

CRITFLAG	=	tests/test_lib.c tests/test_orga.c --coverage -lcriterion

LIBS	=	-L./ -lmy

TEST_LIBS	=	-L./ -lmy

SRC		=   main.c	\
			src/helper.c	\
			src/env.c	\
			src/error_handling.c	\
			src/path_handling.c		\
			src/cd_comand.c		\
			src/option_handler.c	\
			src/fork_usage.c		\
			src/unset_env.c			\
			src/exit.c				\
			src/set_env_solo.c		\
			src/list_to_array.c		\
			src/allias.c			\
			src/array_key.c			\

SRCTEST	=

OBJ		=	$(SRC:.c=.o)

all:	libmy $(NAME)

$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBS)
			@echo -e "\e[1;32m{ Makefile is ready }\e[00;37m"
			@echo -e "\e[1;36m{ Binary is ready }\e[00;37m"

$(UNIT_TEST): libmy
			$(CC) -o $(UNIT_TEST) $(SRCTEST) $(CRITFLAG) $(TEST_LIBS)

tests_run:	$(UNIT_TEST)
			@./$(UNIT_TEST)
			@gcovr --exclude tests/

.PHONY: libmy

libmy:
	$(MAKE) -C lib/my

clean:
			$(MAKE) -C lib/my clean
			@rm -f $(OBJ)
			@rm -f *.gc*
			@rm -f coding-style-reports.log
			@rm -f *~
			@rm -f *.gcda
			@rm -f *.gcno
			@rm -f mysh
			@rm -f libmy.a

fclean:	clean
			$(MAKE) -C lib/my fclean
			@rm -f $(NAME)
			@rm -f $(UNIT_TEST)
			@echo -e "\e[1;33m{ REPOSITORIE as been cleaned }\e[00;37m"


re:	fclean all
