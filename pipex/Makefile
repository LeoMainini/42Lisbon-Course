
SRCS	=	pipex.c

OBJS	=	${SRCS:.c=.o}

PF_NAME	=	ft_printf

LFT_NAME = libft

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
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME):	$(OBJS) $(PF_NAME) $(LFT_NAME)
			@make -C $(PF_NAME) && make -C $(LFT_NAME)
			$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)

all:		${NAME}

clean:	
			
			@$(ECHO) "\033[31mCleaning files in fancy colors"
			@${RM} ${OBJS}
			@make -C $(PF_NAME) clean && make -C $(LFT_NAME) clean

fclean:		clean
			@${RM} ${NAME}
			@make -C $(PF_NAME) fclean && make -C $(LFT_NAME) fclean

re:			fclean	all

