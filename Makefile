SRCS =  so_long.c \
		map_check.c \
		map_check_utils.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \
		mlx_utils.c \
		game_over.c \
		win_game.c	\
		enemies.c	\
		move_enemies.c \
		destroy_game.c \
		image_loader.c	\
		srcs/printf/ft_printf.c srcs/printf/ft_putchar.c srcs/printf/ft_putstr.c srcs/printf/ft_putnbr.c srcs/printf/ft_unbr.c srcs/printf/ft_putnbr_base.c srcs/printf/ft_putvoid.c
NAME = so_long
OBJS = ${SRCS:.c=.o}
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${OBJS} libft.a -Lminilibx-linux -lmlx_Linux -o ${NAME} -lX11 -lXext -fsanitize=leak

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all