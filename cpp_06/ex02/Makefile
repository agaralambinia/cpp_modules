C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS = main.cpp \
	Base.cpp \

OBJ = $(SRCS:.cpp=.o)

NAME = identify

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
