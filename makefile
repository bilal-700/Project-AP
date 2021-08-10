CC = g++
CFLAGS = 

SRC = $(wildcard *.cpp)

OBJ = $(SRC:%.cpp=%)

LIBS = 

all: $(OBJ)

%: %.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ)
