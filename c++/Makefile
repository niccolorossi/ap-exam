MAIN = main.o
CXX = g++
MAINSRC = src/main.cc
CXXFLAGS = -std=c++11 -Wall -Wextra
IFLAGS = -I include 



all: $(MAIN) docs

docs:
	doxygen docs/Doxyfile

$(MAIN): $(MAINSRC)
	$(CXX)  $< -o $(MAIN) $(CXXFLAGS) $(IFLAGS)

clean:
	@rm -fr *.o html latex

.PHONY: all docs clean
