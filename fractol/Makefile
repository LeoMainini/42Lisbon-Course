PF_SRCS	=	ft_printf/ft_putbase10_plus.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	\
			ft_printf/ft_putchar_fd.c		ft_printf/ft_putstr_fd.c	ft_printf/ft_printf.c	\
			ft_printf/ft_printmemory.c

PF_OBJS	=	${PF_SRCS:.c=.o}

SRCS	=	fractol.c	view_utils.c	fractol_gens.c	interaction_hooks.c

OBJS	=	${SRCS:.c=.o}

PF_NAME	=	ft_printf/libftprintf.a

NAME	=	fractol

CC		=	cc

RM		=	rm -f

AR		=	ar rc

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=leak -g

INC		=	-Lft_printf -I . -lftprintf

%.o: %.c
	@echo "\033[32mCompiling $< in fancy colors"
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS) $(PF_NAME)
			$(CC) $(CFLAGS) $(OBJS) $(INC) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(PF_NAME):	${PF_OBJS}
			${AR} $(PF_NAME) $(PF_OBJS)

all:		${NAME}

clean:	
			
			@echo "\033[31mCleaning files in fancy colors"
			@${RM} ${OBJS} ${PF_OBJS}

fclean:		clean
			@${RM} ${NAME} ${PF_NAME}

re:			fclean	all

