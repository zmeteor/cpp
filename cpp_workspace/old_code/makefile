src = $(wildcard *.cpp)
targets = $(patsubst %.cpp, %, $(src))

CC = g++

all:$(targets)

$(targets):%:%.cpp
	$(CC) $< -o $@

.PHONY:clean all
clean:
	-rm -rf $(targets) 

