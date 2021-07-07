NAME	= philo

CFLAGS	+= -Wall -Wextra -Werror
SRCS	=	main.c ft_error.c ft_init.c utils.c\
			ft_eat.c ft_putmessage.c \

OBJS	= $(SRCS:.c=.o)

LIBS	= -lpthread

all: $(NAME)

$(NAME):	$(OBJS)
			gcc ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re