C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	HumanA.cpp \
	HumanB.cpp \
	Weapon.cpp \

OBJ = $(SRCS:.cpp=.o)

NAME = violence

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
