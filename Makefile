NAME = bsq

CC = cc

CFLAGS = -Wall -Wextra -Werror

ROOT_DIRS = ./srcs/

HEAD = ./includes/

SRC = main.c

SRCS = ${addprefix ${ROOT_DIRS}, ${SRC}}

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o $@

${NAME} :  ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} $^

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

.PHONY: all fclean
