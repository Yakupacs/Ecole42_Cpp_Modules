NAME	=	c_zombie
SRCS	=	main.cpp zombieHorde.cpp Zombie.cpp
OBJS	=	$(SRCS:.cpp=.o)
CC		=	c++
RM		=	rm -f
FLAGS	=	-Wall -Werror -Wextra -std=c++98


all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
