C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp \
		PhoneBook.cpp \
		commands.cpp \
		main.cpp \

OBJ = $(SRCS:.cpp=.o)

NAME = phonebook

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
