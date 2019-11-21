##
## EPITECH PROJECT, 2019
## SpaceshipWarriorCombatED
## File description:
## Makefile
##


SRC =	./src/Client.cpp \
		./src/network/NetworkManager.cpp

UT_SRC = 	

UT  =   unit_tests

MAIN = ./src/Main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE = -I./include -I ../lib/udp/include

CXXFLAGS	=	$(INCLUDE) -Wall -Wextra -Werror -g3

NAME = 	r-type_client

LDFLAGS =   -lcriterion -lgcov --coverage

all: $(NAME)

$(NAME): $(OBJ) $(MAIN:.cpp=.o)
		g++ -o $(NAME) $(OBJ) $(MAIN:.cpp=.o) $(CXXFLAGS) -L../lib/udp -ludp

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