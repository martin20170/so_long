SRCS = ft_calloc.c ft_isdigit.c ft_memcmp.c ft_putchar_fd.c ft_split.c ft_strjoin.c ft_strmapi.c ft_strtrim.c \
ft_atoi.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_substr.c \
ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
ft_isascii.c ft_memchr.c ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlen.c ft_strrchr.c ft_toupper.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_printf.c base_ten_to_m.c ft_printf_options_1.c \
ft_printf_options_2.c get_next_line.c get_next_line_utils.c ft_fill_c_by_c.c

OBJDIR = objs

OBJS = ${addprefix ${OBJDIR}/,${SRCS:.c=.o}}

NAME = libft.a

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

ARRC = ar rcs

${NAME}:
			make all -C essentials
			make all -C ft_printf
			make all -C get_next_line
			${ARRC} ${NAME} ${OBJS}

all:	${NAME}

clean:
		make clean -C essentials
		make clean -C ft_printf
		make clean -C get_next_line

fclean:	clean
		rm -f ${NAME}

re: fclean all

.PHONY : all clean fclean re
