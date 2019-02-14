SRC = main.cc
EXE = $(SRC:.cc=.x)

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): src/main.o
	$(CXX) $^ -o $(EXE)

main.o: src/main.cc

BST.o: include/BST.h

format: $(SRC) include/BST.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -rf *.o main.x $(EXE) *~ *~

.PHONY: clean all format
