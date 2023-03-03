NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

SRCS = main.c init_list.c instructions/s.c instructions/p.c instructions/r.c instructions/rr.c argument.c utils.c tri.c

OBJC = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean: 
	 ${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all
