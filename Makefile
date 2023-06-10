CC = cc
CFLAGS = -Wall -Wextra -Werror -g
ARFLAGS = rc
NAME = push_swap
INCD = push_swap.h
SRCD = main.c main_utill.c parsing.c tools.c ft_atoi_pro.c command.c\
		sort_stack.c sort_utill.c hard_sort.c hard_sort2.c hard_three.c\
		sort_a_case.c sort_b_case.c print.c
OBJS = $(SRCD:.c=.o)
LIBDIR = ./libft/

BONUS = checker
INCD_B = checker.h
SRC_B = command_bonus.c ft_atoi_pro_bonus.c main_bonus.c gnl_bonus.c\
		main_utill_bonus.c parsing_bonus.c tools_bonus.c gnl2_bonus.c
OBJ_B = $(SRC_B:.c=.o)

$(NAME) : $(OBJS)
	make -C $(LIBDIR) all
	$(CC) $(OBJS) -L $(LIBDIR) -l ft -o $(NAME)

$(BONUS) : $(OBJ_B)
	make -C $(LIBDIR) all
	$(CC) $(OBJ_B) -L $(LIBDIR) -l ft -o $(BONUS)

all : $(NAME)
bonus : $(BONUS)
clean :
	make -C $(LIBDIR) clean
	rm -rf $(OBJS) $(OBJ_B)
fclean : clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME) $(BONUS)
re : fclean all
.PHONY : all clean fclean re