NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	push_swap.c \
		sort1.c \
		sort2.c \
		checks.c \
		utils.c \
		pa_pb_sa_sb_ss.c \
		ra_rb_rr.c \
		rra_rrb_rrr.c

SRCSB = checker_bonus.c \
		checker_utils_bonus.c \
		checks_bonus.c \
		utils_bonus.c \
		pa_pb_sa_sb_ss_bonus.c \
		ra_rb_rr_bonus.c \
		rra_rrb_rrr_bonus.c 

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

LIBFT = ./libft/libft.a

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(CHECKER): $(LIBFT) $(OBJSB)
	$(CC) $(CFLAGS) $^ -o $(CHECKER)

$(LIBFT): ./libft/libft.h
	make -C ./libft

$(OBJS): %.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSB): %.o: %.c checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER)

all: $(NAME) $(CHECKER)

clean:
	make -C ./libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJSB)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)
	rm -rf $(CHECKER)

re: fclean $(NAME)

.PHONY: clean