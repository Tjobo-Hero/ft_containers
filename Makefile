# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: timvancitters <timvancitters@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/26 16:27:02 by timvancitte   #+#    #+#                  #
#    Updated: 2021/04/29 09:42:25 by timvancitte   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

SOURCES			= 	TEST/main.cpp \
					TEST/catch.cpp \
					TEST/List_test.cpp \
					# TEST/Queue_test.cpp \
					# TEST/Stack_test.cpp \
					# TEST/Vector_test.cpp \
					# TEST/RandomAccesIterator_test.cpp \
					# TEST/BiDirectionalIterator_test.cpp \
					TEST/Map_test.cpp \

OBJECTS 		=	${SOURCES:%.c=%.o}

FLAGS 			=	-Wall -Wextra -Werror
INCLUDES 		=	-IINCLUDES/
TEST			=	-ITEST/
COMPILE			=	clang++ -std=c++14

GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)----------------------------------------------------"
	$(COMPILE) $(INCLUDES) $(TEST) $(FLAGS) -g3 -o  $(NAME) $(OBJECTS)
	@echo "Executable				./ft_containers"
	@echo "$(GREEN)----------------------------------------------------"

%.o: %.c
	@echo "$(GREY)Compiling...				$(WHITE)$<"
	$(COMPILE) $(INCLUDES) $(UNIT_TEST) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE ./ft_containers"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

fclean:	clean
	@echo "$(RED)----------------------------------------------------"
	@echo "$(WHITE)DELETE ./ft_containers"
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(NAME)

re: clean all

.PHONY: all clean re