CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INC = -I./
NAME = convert
SRCS = main.cpp \
	   ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c -o $@ $^
