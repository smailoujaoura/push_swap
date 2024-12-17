NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = 	1main.c \
		2checks.c \
		3utils.c \
		4sort1.c \
		5ops.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean