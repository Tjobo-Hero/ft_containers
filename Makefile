# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: timvancitters <timvancitters@student.co      +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/26 16:27:02 by timvancitte   #+#    #+#                  #
#    Updated: 2021/04/15 11:02:31 by timvancitte   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_containers

SOURCES			= 	TEST/main.cpp \
					TEST/Vector_test.cpp \
					TEST/List_test.cpp \
					TEST/catch.cpp \
					# UNIT_TEST/1_Bidirectionaliterator_test.cpp \
					# UNIT_TEST/2_RandomAccessIterator_test.cpp \
					UNIT_TEST/3_list_test.cpp \
					# UNIT_TEST/5_queue_test.cpp \
					# UNIT_TEST/6_stack_test.cpp \
					# UNIT_TEST/7_map_test.cpp \

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

re: clean all

.PHONY: all clean re