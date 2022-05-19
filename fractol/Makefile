PF_SRCS	=	ft_printf/ft_putbase10_plus.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	\
			ft_printf/ft_putchar_fd.c		ft_printf/ft_putstr_fd.c	ft_printf/ft_printf.c	\
			ft_printf/ft_printmemory.c

PF_OBJS	=	${PF_SRCS:.c=.o}

SRCS	=	fractol.c

OBJS	=	${SRCS:.c=.o}

PF_NAME	= ft_printf/libftprintf.a

NAME = fractol

CC		= cc

RM		= rm -f

AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):	$(OBJS) PF_NAME
			$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -Lft_printf -I . -lftprintf -framework OpenGL -framework AppKit -o $(NAME)

PF_NAME:	${PF_OBJS}
			${AR} ${PF_NAME} ${PF_OBJS}

all:		${NAME}

clean:			
			${RM} ${OBJS} ${PF_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean	all

