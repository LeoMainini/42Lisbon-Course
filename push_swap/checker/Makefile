
SRCS	=	list_funtions/ft_lstiterf.c	list_funtions/ft_lstnew.c	list_funtions/ft_lstsize.c	\
			list_funtions/push_func.c	list_funtions/rotate_func.c	list_funtions/swap_func.c	\
			get_next_line.c				get_next_line_utils.c		input_checks.c				\
			checker.c					utils.c						ft_split.c					\
			ft_strncmp.c				checker_utils.c

OBJS	=	${SRCS:.c=.o}

PF_NAME	=	ft_printf/libftprintf.a

LFT_NAME = libft/libft.a

NAME	=	checker

ifeq ($(shell uname),Linux)
	ECHO	=	echo -e
else
	ECHO	=	echo
endif

CC		=	cc

RM		=	rm -f

AR		=	ar rc

CFLAGS	=	-Wall -Werror -Wextra -D BUFFER_SIZE=1 -fsanitize=address -g -lm

INC		=	 -Lft_printf -I . -lftprintf #-lft -Llibft

%.o: %.c
	@$(CC) $(CFLAGS) -Wall -Wextra -Werror -c $< -o $@

$(NAME):	$(OBJS) $(PF_NAME) #$(LFT_NAME)
			@printf "\nCompiling $(NAME)\n"
			@$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)

$(PF_NAME):
			@make -C ft_printf -s

$(LFT_NAME):
			@make -C libft

all:		${NAME}

clean:	
			@printf "\nCleaning $(NAME)\n"
			@${RM} ${OBJS}
			@make -C ft_printf clean -s #&& make -C libft clean

fclean:		clean
			@${RM} ${NAME}
			@make -C ft_printf fclean -s #&& make -C libft fclean

re:			fclean	all

