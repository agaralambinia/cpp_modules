C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp \
	tests.cpp \

OBJ = $(SRCS:.cpp=.o)

NAME = the_job_of_your_dreams

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
