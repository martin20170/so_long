SRCS = main.c events.c graphics.c map_utils.c map_checker.c map_checker_utils.c utils.c

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARRC = ar rcs



${NAME}:	${SRCS}
				make all -C ./libft
				${CC} ${CFLAGS} -I ./minilibx-linux -L ./minilibx-linux -o ${NAME} ${SRCS} libft/libft.a -lmlx -lXext -lX11 -lm



all:	${NAME}


clean:
				make clean -C ./libft

fclean:	clean
				rm -f ${NAME}
				make fclean -C ./libft

re: fclean all

.PHONY : all clean fclean re
