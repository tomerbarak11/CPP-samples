CC=g++

CPPFLAGS = -I../include
CXXFLAGS = -g -pedantic -ansi -Wall -Werror -std=c++03
LDFLAGS = -g

TARGET = test
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET) run

$(TARGET) : $(OBJECTS)

include depends
depends:
	$(CC) -MM $(CPPFLAGS) $(SOURCES) > depends

clean:
	rm -f $(TARGET) *.o *.gch depends

run: $(TARGET)
	./$(TARGET) -v

