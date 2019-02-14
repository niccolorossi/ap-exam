MAIN = main.x
CXX = g++
MAINSRC = src/main.cc
CXXFLAGS = -std=c++11 -Wall -Wextra


all: $(MAIN)

$(MAIN): $(MAINSRC)
	$(CXX) -g $< -o $(MAIN) $(CXXFLAGS)

clean:
	@rm -fr *.o

.PHONY: clean all
