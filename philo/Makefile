NAME = philo

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror 

UTILS = utils/arg_checker.c \
		utils/ft_atol.c \
		utils/utils.c 
		

SRCS = $(UTILS)\
		init.c \
		philo_routine.c \
		monitor.c \
		 main.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -pthread

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus
