BEN = benchmark.x
TEST = test.x
CXX = g++
BENSRC = src/benchmark.cpp
TESTSRC = src/test.cpp
CXXFLAGS = -std=c++11 -Wall -Wextra
IFLAGS = -I include



all: $(BEN) $(TEST) docs

docs:
	doxygen docs/Doxyfile

$(BEN): $(BENSRC)
	$(CXX)  $< -o $@ $(CXXFLAGS) $(IFLAGS)

$(TEST): $(TESTSRC)
	$(CXX)  $< -o $@ $(CXXFLAGS) $(IFLAGS)

clean:
	@rm -fr *.x html latex
.PHONY: all docs clean
