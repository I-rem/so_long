NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS        := so_long.c                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
