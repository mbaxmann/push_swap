OBJS    =       ${SRCS:.c=.o}

SRCS	=	srcs/main.c srcs/ft_init.c srcs/ft_algo.c srcs/ft_set_operator.c srcs/ft_set_operator_2.c srcs/ft_set_operator_3.c srcs/ft_sort_big.c srcs/ft_sort_big_2.c srcs/ft_quicksort.c srcs/ft_quicksort_2.c

CC      =       clang

FLAGS   =       -Wall -Wextra -Werror

NAME    =       push_swap

LINK	=	-lft

LIB     =       libft/libft.a

RM      =       rm -rf

LIB_PATH	=	-L ./libft/

all:    ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:        ${OBJS}
		make -C libft
		${CC} ${LIB_PATH} -o ${NAME} ${OBJS} ${LINK}

clean:
	make clean -C libft
	${RM} ${OBJS}

fclean:         clean
	make fclean -C libft
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
