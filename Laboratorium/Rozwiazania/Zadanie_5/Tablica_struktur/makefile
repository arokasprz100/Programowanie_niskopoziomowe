CXX = g++ -g -Wall -Wextra -std=c++11 -pedantic-errors
DEP_FLAGS = -MMD -MP

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

CXXFLAGS+=$(DEP_FLAGS)

TARG = Zadanie_5

all: $(TARG)

$(TARG): $(OBJ)
	$(CXX) $^$(LFLAGS) -o $@

$(OBJ) : $(SRC)
	$(CXX) -c $(SRC) $(DEP_FLAGS)

.PHONY: clean

clean:
	rm $(OBJ) $(TARG) $(DEP)

-include $(DEP)
