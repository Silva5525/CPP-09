# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdegraf <wdegraf@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 18:09:33 by wdegraf           #+#    #+#              #
#    Updated: 2025/05/06 12:41:11 by wdegraf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe

SRC := $(wildcard *.cpp)

CC := c++
CPPFLAGS := -std=c++17 -Wall -Wextra -Werror  

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

-include $(SRC:.cpp=.d)

%.d: %.cpp
	@$(CC) $(CPPFLAGS) -MM $< > $@

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

run: all
	./$(NAME)

debug: CPPFLAGS += -g -fsanitize=address
debug: re

clean:
	@rm -f *.o *.d

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re debug
