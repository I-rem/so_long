NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror

SRCS        :=      so_long.c get_next_line.c get_next_line_utils.c windows_hooks.c

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

$(NAME): ${OBJS}
			
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit


all:		${NAME}

clean:
			 ${RM} *.o */*.o */*/*.o
			 rm -rf $(NAME).dSYM >/dev/null 2>&1


fclean:		clean
			 ${RM} ${NAME}
			 rm libmlx.a

re:			fclean all

.PHONY:		all clean fclean re
