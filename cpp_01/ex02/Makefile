C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \

OBJ = $(SRCS:.cpp=.o)

NAME = hi_this_is_brain

all: $(NAME)

$(NAME):$(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
