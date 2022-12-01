CC = g++
CFLAGS = -c -O3 -std=c++11 -Wall
LDFLAGS = -I. -ldl
SOURCES = order.cpp vision.cpp
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS := $(addprefix objects/,$(OBJECTS))
EXECUTABLE = vision

all: objects $(SOURCES) $(EXECUTABLE)

objects:
	@mkdir -p objects

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

objects/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf objects/*.o $(EXECUTABLE)
