
SRCS	=	pipex.c		utils.c		process_utils.c		init_utils.c	\
			argument_processing.c

OBJS	=	${SRCS:.c=.o}

PF_NAME	=	ft_printf/libftprintf.a

LFT_NAME = libft/libft.a

NAME	=	pipex

ifeq ($(shell uname),Linux)
	ECHO	=	echo -e
else
	ECHO	=	echo
endif

CC		=	cc

RM		=	rm -f

AR		=	ar rc

CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g -lm

INC		=	 -Lft_printf -Llibft -I . -lftprintf -lft

%.o: %.c
	@$(ECHO) "\033[32mCompiling $< in fancy colors"
	@$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME):	$(OBJS) $(PF_NAME) $(LFT_NAME)
			$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)

$(PF_NAME):
			@make -C ft_printf

$(LFT_NAME):
			@make -C libft

all:		${NAME}

clean:	
			
			@$(ECHO) "\033[31mCleaning files in fancy colors"
			@${RM} ${OBJS}
			@make -C ft_printf clean && make -C libft clean

fclean:		clean
			@${RM} ${NAME}
			@make -C ft_printf fclean && make -C libft fclean

re:			fclean	all

