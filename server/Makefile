##
## EPITECH PROJECT, 2019
## SpaceshipWarriorCombatED
## File description:
## Makefile
##


SRC =	./src/Server.cpp \
		./src/UDP.cpp \

UT_SRC = 	

UT  =   unit_tests

MAIN = ./src/Main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE = -I./include

CXXFLAGS	=	$(INCLUDE) -Wall -Wextra -Werror

NAME = 	r-type_server

LDFLAGS =   -lcriterion -lgcov --coverage

all: $(NAME)

$(NAME): $(OBJ) $(MAIN:.cpp=.o)
		g++ -o $(NAME) $(OBJ) $(MAIN:.cpp=.o) $(CXXFLAGS)

debug: $(OBJ) $(MAIN:.cpp=.o)
		g++ -o $(NAME) $(OBJ) $(MAIN:.cpp=.o) $(CXXFLAGS) -g3

clean:
		rm -f $(OBJ)
		rm -f $(MAIN:.cpp=.o) 
		rm -f *.gc*
		rm -f vgcore.*

fclean:		clean
		rm -f $(NAME)
		rm -f $(UT)

re:		fclean all

tests_run:
		g++ -o $(UT) $(UT_SRC) $(INCLUDE) $(SRC) $(CXXFLAGS) $(LDFLAGS) 
		./$(UT) --always-succeed