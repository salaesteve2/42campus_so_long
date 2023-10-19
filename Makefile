SRCS = proces_map.c get_next_line.c get_next_line_utils.c main.c map_lines.c ft_printf_map.c ft_dimensiones.c ft_mapa.c ft_inicio.c ft_keyhook.c ft_posiciones.c

SRCBS = bonus/ft_img_personaje2_bonus.c bonus/ft_mapa2_bonus.c bonus/ft_img_personaje_bonus.c bonus/ft_img_enemigos_bonus.c bonus/ft_itoa_bonus.c bonus/ft_img_bonus.c bonus/proces_map_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/main_bonus.c bonus/map_lines_bonus.c bonus/ft_printf_map_bonus.c bonus/ft_dimensiones_bonus.c bonus/ft_mapa_bonus.c bonus/ft_inicio_bonus.c bonus/ft_keyhook_bonus.c bonus/ft_posiciones_bonus.c

OBJS = ${SRCS:.c=.o}

OBJBS = ${SRCBS:.c=.o}

NAME = so_long

BONUS = so_long_bonus

CC = gcc 

FLAGS = -Wall -Wextra -Werror

SL = -framework OpenGL -framework AppKit

CI = -I sl_inc/

RM = rm -f

LIBMLX = mlx/libmlx.a

${NAME}: ${SRCS} ${LIBMLX}
	${CC} ${FLAGS} ${CF} ${CI} ${SL} ${SRCS} ${LIBMLX} -o ${NAME}

${BONUS}: ${SRCBS} ${LIBMLX}
	${CC} ${FLAGS} ${CF} ${CI} ${SL} ${SRCBS} ${LIBMLX} -o ${BONUS}

${LIBMLX}:
	make -C mlx/

all: ${NAME}

clean: 
		${RM} ${OBJS}
		${RM} ${OBJBS} 

bonus: ${BONUS}

fclean: clean 
		${RM} ${NAME}
		${RM} ${BONUS}
		make clean -C mlx/

re: fclean all

.PHONY: all clean fclean re bonus