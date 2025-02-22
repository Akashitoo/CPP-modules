NAME = Zombie

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME):$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean:
		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re