PF_SRCS	=	ft_printf/ft_putbase10_plus.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	\
			ft_printf/ft_putchar_fd.c		ft_printf/ft_putstr_fd.c	ft_printf/ft_printf.c	\
			ft_printf/ft_printmemory.c

PF_OBJS	=	${PF_SRCS:.c=.o}

OBJS	=	fractol.c

PF_NAME	= ft_printf/libftprintf.a

NAME = fratol

CC		= cc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
%.o: %.c
			$(CC) ${CFLAGS} -Imlx -c $< -o $@

$(NAME):	${OBJS} printf
			$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

printf:		${PF_OBJS}
			${AR} ${PF_NAME} ${PF_OBJS}

all:		${NAME}

clean:			
			${RM} ${OBJS} ${PF_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean	all

