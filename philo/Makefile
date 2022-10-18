
SRCS	=	philo.c			arg_processing.c	arg_processing_utils.c		\
			initializers.c	simulation.c		sim_utils.c					\
			routine_utils.c		\

OBJS	=	${SRCS:.c=.o}

NAME	=	philo

ifeq ($(shell uname),Linux)
	ECHO	=	echo
else
	ECHO	=	echo
endif

CC		=	cc

RM		=	rm -f

AR		=	ar rc

CFLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=thread

INC		=	-pthread

%.o: %.c
	@$(ECHO) "\033[32mCompiling $< in fancy colors"
	@$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(INC) -o $(NAME)

all:		${NAME}

clean:	
			
			@$(ECHO) "\033[31mCleaning files in fancy colors"
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean	all

