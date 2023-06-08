CC = cc
CFLAGS = -Wall -Wextra -Werror -g
ARFLAGS = rc
NAME = push_swap
INCD = push_swap.h
SRCD = main.c main_utill.c tools.c ft_atoi_pro.c command.c\
		sort_stack.c sort_utill.c hard_sort.c hard_sort2.c hard_three.c\
		sort_a_case.c sort_b_case.c print.c
OBJS = $(SRCD:.c=.o)
LIBDIR = ./libft/

$(NAME) : $(OBJS)
	make -C $(LIBDIR) all
	$(CC) $(OBJS) -L $(LIBDIR) -l ft -o $(NAME)
# cp $(LIBDIR)libft.a ./$(NAME)
# ar $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)
clean :
	make -C $(LIBDIR) clean
	rm -rf $(OBJS)
fclean : clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)
re : fclean all
.PHONY : all clean fclean re