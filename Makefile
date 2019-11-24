##
## EPITECH PROJECT, 2019
## SpaceshipWarriorCombatED
## File description:
## Makefile
##


SRC =	GameEngine/EntityManager.cpp \
		GameEngine/GameEngine.cpp \
		GameEngine/System/Render.cpp \
		Rtype/Rtype.cpp \
		Sfml/Sfml.cpp \

UT_SRC =

UT  =   unit_tests

MAIN = ./Rtype/main.cpp

OBJ = $(SRC:.cpp=.o)

INCLUDE = -I./ -I./GameEngine -I./GameEngine/Component -I./GameEngine/System -I./Rtype

CXXFLAGS	=	$(INCLUDE) -Wall -Wextra -Werror -std=c++14

NAME = 	r-type

LDFLAGS =   -lcriterion -lgcov --coverage

all: $(NAME)

$(NAME): $(OBJ) $(MAIN:.cpp=.o)
		g++ -o $(NAME) $(OBJ) $(MAIN:.cpp=.o) $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
debug: $(OBJ) $(MAIN:.cpp=.o)
		g++ -o $(NAME) $(OBJ) $(MAIN:.cpp=.o) $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -g3

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