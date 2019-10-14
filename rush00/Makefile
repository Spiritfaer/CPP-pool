.PHONY: all clean fclean re

NAME    =   ft_retro
CC      =   clang++
FLAGS   =   -Wall -Wextra -Werror
SRC     =   $(CLASS_HEAD:.hpp=.cpp)
OBJ     =   $(SRC:.cpp=.o)
NCURSES =   -lncurses

CLASS_HEAD = 	main.hpp \
                Vec2D.hpp \
				Object.hpp \
				Player.hpp \
				World.hpp \
				Enemy.hpp \
				Ball.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(NCURSES) $(OBJ)

%.o: %.cpp $(CLASS_HEAD)
	$(CC) -c $(FLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
