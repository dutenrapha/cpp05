
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -Wshadow
CC = c++
FILE = main.cpp  Bureaucrat.cpp Form.cpp
NAME = main 

all: $(NAME)

fclean:
	rm -f $(NAME)
	rm -f *.o

test:
	./$(NAME)

re: fclean all test

$(NAME):
	$(CC) $(FLAGS) $(FILE) -o $@
