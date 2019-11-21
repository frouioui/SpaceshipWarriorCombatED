## ------------- COMPLILATION ------------- ##
CXX	=	g++ $(INCLUDE)

## ------------- UNIT TESTS ------------- ##
UT_DIR	=	./tests

UT	=	unit_test_udp

UT_SRC	=	$(UT_DIR)/udp_tests.cpp

## ------------- LIB ------------- ##
LIB_DIR	=	./src

LIB_SRC	=	$(LIB_DIR)/UDP.cpp	\

LIB_NAME	=	libudp.a

LIB_FLAG	=

## ---------------- FLAGS ----------------- ##
INCLUDE	=	-I./include/

CXXFLAGS	+=	-W -Wall -Wextra -Werror

LDFLAGS	=	-lcriterion -lgcov --coverage

LIB_OBJ	=	$(LIB_SRC:.cpp=.o)

all:	$(LIB_NAME)

$(LIB_NAME):	main

main: $(LIB_OBJ)
	ar rc $(LIB_NAME) $(LIB_OBJ)
	ar t $(LIB_NAME)

tests_run: tests_compile
	./$(UT)

tests_compile:
	$(CXX) -o $(UT) $(UT_SRC) $(LIB_OBJ) $(LDFLAGS) -I ./include

clean:
	rm -f $(LIB_OBJ) *.gc*
	rm -f ./include/*.gch

fclean:	clean
	rm -f $(LIB_NAME) $(LIB_NAME) $(UT) *.a

re:	fclean all