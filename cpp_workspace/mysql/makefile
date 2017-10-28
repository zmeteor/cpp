
SRCS = $(wildcard *.cpp)

OBJS = $(patsubst %.cpp,%.o,$(SRCS))

INCL=-I/usr/include/mysql/include -I./
LIB=-L/usr/lib/mysql/lib -lmysqlclient #-static -lpthread -ldl 
.SUFFIXES: .o .cpp

EXE=./test

all:$(EXE)

$(EXE):$(OBJS)
	g++ $(INCL) -o $(EXE) $^ $(LIB) 
	
.cpp.o:
	g++ $(INCL) -c $< 

clean:
	 rm -f $(OBJS) $(EXE)

