CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=group_proc.cpp Line.cpp GTFRecord.cpp Gene.cpp
OBJECTS=$(SOURCES:.cpp=.o)
PROGRAMS=group_proc

all: $(SOURCES) $(PROGRAMS)

$(PROGRAMS): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(PROGRAMS)
