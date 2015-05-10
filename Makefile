##
## Makefile for Makefile in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq
## 
## Made by michael besnainou
## Login   <besnai_m@epitech.net>
## 
## Last update Sat Apr 11 17:10:50 2015 Amlan BARUA
##

SRC	= asm/src/parserchamp.c

SRC2	= corewar/src/main.c \
	corewar/src/memory.c \
	corewar/src/get_champ_header.c 

SRCS	= lib/my/my_putchar.c \
	lib/my/my_strlen.c \
	lib/my/my_putstr.c \
	lib/my/my_put_nbr.c \
	lib/my/my_putstr_error.c \
	lib/my/get_next_line.c \
	lib/my/my_putchar_fd.c \
	lib/my/my_strncmp.c \
	lib/my/my_strcat.c \
	lib/my/my_get_nbr.c 


OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -rf

LIB	= libmy.a

NAME	= asm/asm

NAME2	= corewar/corewar

CFLAGS	= -W -Wall -Wextra -Iinclude/

all: $(LIB) $(NAME) $(NAME2)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

$(NAME): $(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

$(NAME2): $(LIB) $(OBJ2)
	$(CC) -o $(NAME2) $(OBJ2) $(LIB)

clean: 
	$(RM) $(OBJ)
	$(RM) $(OBJ2)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB)
	$(RM) $(NAME)
	$(RM) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
