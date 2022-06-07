PF_SRCS	=	ft_printf/ft_putbase10_plus.c	ft_printf/ft_putnbr_fd.c	ft_printf/ft_strlen.c	\
			ft_printf/ft_putchar_fd.c		ft_printf/ft_putstr_fd.c	ft_printf/ft_printf.c	\
			ft_printf/ft_printmemory.c

PF_OBJS	=	${PF_SRCS:.c=.o}

SRCS	=	ps.c	ft_split.c	input_checks.c	list_funtions/ft_lstnew.c	\
			list_funtions/ft_lstsize.c	list_funtions/ft_lstiterf.c			\
			list_funtions/swap_func.c	list_funtions/rotate_func.c			\
			list_funtions/push_func.c	sorting_func2.c		sorting_func.c

OBJS	=	${SRCS:.c=.o}

PF_NAME	=	ft_printf/libftprintf.a

NAME	=	push_swap

CC		=	cc

RM		=	rm -f

AR		=	ar rc

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g -lm

INC		=	 -Lft_printf -I . -lftprintf

%.o: %.c
	@echo -e "\033[32mCompiling $< in fancy colors"
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(PF_NAME)
			$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)

$(PF_NAME):	${PF_OBJS}
			${AR} $(PF_NAME) $(PF_OBJS)

all:		${NAME}

clean:	
			
			@echo -e "\033[31mCleaning files in fancy colors"
			@${RM} ${OBJS} ${PF_OBJS}

fclean:		clean
			@${RM} ${NAME} ${PF_NAME}

re:			fclean	all

