SRCS =  so_long.c \
		map_check.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c
NAME = so_long
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} libft.a -Lminilibx-linux -lmlx_Linux -o ${NAME} -lX11 -lXext

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all