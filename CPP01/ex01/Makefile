NAME = zombiehorde
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp Zombie.cpp zombieHorde.cpp
OBJS = $(SRCS:.cpp=.o)

.SECONDARY: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -f *.o
	
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re