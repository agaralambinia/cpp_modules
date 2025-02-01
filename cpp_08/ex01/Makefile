C++ = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -fsanitize=address

SRCS = main.cpp \
	Span.cpp \

OBJ = $(SRCS:.cpp=.o)

NAME = span

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
