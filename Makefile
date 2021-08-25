CXX = g++
CXXFLAGS = -Wall

all: build build/output

build:
	mkdir build

build/output: build/main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@