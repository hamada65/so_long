SRCS =  so_long.c \
		map_check.c \
		map_check_utils.c \
		mlx_utils.c \
		win_game.c	\
		destroy_game.c \
		image_loader.c \
		mlx_utils2.c \
		player_movement.c \
		map_read.c \
		mlx_utils3.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \
		srcs/printf/ft_printf.c srcs/printf/ft_putchar.c srcs/printf/ft_putstr.c srcs/printf/ft_putnbr.c srcs/printf/ft_unbr.c srcs/printf/ft_putnbr_base.c srcs/printf/ft_putvoid.c \
		srcs/libft/ft_isalpha.c srcs/libft/ft_isdigit.c srcs/libft/ft_isalnum.c srcs/libft/ft_isascii.c srcs/libft/ft_isprint.c srcs/libft/ft_strlen.c \
		srcs/libft/ft_toupper.c srcs/libft/ft_tolower.c srcs/libft/ft_strchr.c srcs/libft/ft_strrchr.c srcs/libft/ft_strncmp.c \
		srcs/libft/ft_memcpy.c srcs/libft/ft_memmove.c srcs/libft/ft_memset.c srcs/libft/ft_memcmp.c srcs/libft/ft_memchr.c srcs/libft/ft_bzero.c \
		srcs/libft/ft_strnstr.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlcat.c srcs/libft/ft_atoi.c srcs/libft/ft_strdup.c srcs/libft/ft_calloc.c \
		srcs/libft/ft_substr.c srcs/libft/ft_strjoin.c srcs/libft/ft_split.c srcs/libft/ft_itoa.c srcs/libft/ft_strmapi.c \
		srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putendl_fd.c \
		srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strtrim.c  srcs/libft/ft_striteri.c \
		srcs/libft/ft_lstnew.c srcs/libft/ft_lstlast.c srcs/libft/ft_lstadd_front.c srcs/libft/ft_lstsize.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstclear.c\
		srcs/libft/ft_lstdelone.c srcs/libft/ft_lstiter.c srcs/libft/ft_lstmap.c
SRCS_BONUS = so_long_bonus.c \
			map_check_bonus.c \
			map_check_utils_bonus.c \
			mlx_utils_bonus.c \
			game_over_bonus.c \
			win_game_bonus.c	\
			enemies_bonus.c	\
			move_enemies_bonus.c \
			destroy_game_bonus.c \
			image_loader_bonus.c \
			mlx_utils2_bonus.c \
			player_movement_bonus.c \
			frames_calculate_bonus.c \
			map_read_bonus.c \
			mlx_utils3_bonus.c \
			srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c \
			srcs/printf/ft_printf.c srcs/printf/ft_putchar.c srcs/printf/ft_putstr.c srcs/printf/ft_putnbr.c srcs/printf/ft_unbr.c srcs/printf/ft_putnbr_base.c srcs/printf/ft_putvoid.c \
			srcs/libft/ft_isalpha.c srcs/libft/ft_isdigit.c srcs/libft/ft_isalnum.c srcs/libft/ft_isascii.c srcs/libft/ft_isprint.c srcs/libft/ft_strlen.c \
			srcs/libft/ft_toupper.c srcs/libft/ft_tolower.c srcs/libft/ft_strchr.c srcs/libft/ft_strrchr.c srcs/libft/ft_strncmp.c \
			srcs/libft/ft_memcpy.c srcs/libft/ft_memmove.c srcs/libft/ft_memset.c srcs/libft/ft_memcmp.c srcs/libft/ft_memchr.c srcs/libft/ft_bzero.c \
			srcs/libft/ft_strnstr.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strlcat.c srcs/libft/ft_atoi.c srcs/libft/ft_strdup.c srcs/libft/ft_calloc.c \
			srcs/libft/ft_substr.c srcs/libft/ft_strjoin.c srcs/libft/ft_split.c srcs/libft/ft_itoa.c srcs/libft/ft_strmapi.c \
			srcs/libft/ft_putchar_fd.c srcs/libft/ft_putstr_fd.c srcs/libft/ft_putendl_fd.c \
			srcs/libft/ft_putnbr_fd.c srcs/libft/ft_strtrim.c  srcs/libft/ft_striteri.c \
			srcs/libft/ft_lstnew.c srcs/libft/ft_lstlast.c srcs/libft/ft_lstadd_front.c srcs/libft/ft_lstsize.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstclear.c\
			srcs/libft/ft_lstdelone.c srcs/libft/ft_lstiter.c srcs/libft/ft_lstmap.c
NAME = so_long
NAME_BONUS = so_long_bonus
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: ${NAME}

.SECONDARY: ${OBJS} ${OBJS_BONUS}

${NAME}: ${OBJS}
	${CC} $(CFLAGS) ${OBJS} -Lminilibx-linux -lmlx_Linux -o ${NAME} -lX11 -lXext

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} $(CFLAGS) ${OBJS_BONUS} -Lminilibx-linux -lmlx_Linux -o ${NAME_BONUS} -lX11 -lXext

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}

re: fclean all