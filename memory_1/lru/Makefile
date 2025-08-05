SOURCES := $(wildcard *.cpp)
RESULT := main
SCRIPTS := $(wildcard *.sh)
SCRIPT_TARGETS := $(SCRIPTS:.sh=_run)

ifeq ($(OS), Windows_NT)
    USER_OS := Windows
else
    USER_OS := $(shell uname -s)
endif

ifneq ($(USER_OS), Darwin)
	ASAN_OPTIONS := detect_leaks=1
endif

OBJECTS := $(SOURCES:.cpp=.o)
CFLAGS := -g -std=c++2a -Wall -Werror

all: run

run: compile
	./$(RESULT)

%_run: %.sh
	/bin/bash $<

compile: $(SOURCES) $(RESULT) $(SCRIPT_TARGETS)

.cpp.o: $(wildcard *.h)
	g++ -c $(CFLAGS) $< -o $@

$(RESULT): $(OBJECTS)
	g++ $(OBJECTS) $(LDFLAGS) -o $(RESULT)

clean:
	del -f $(OBJECTS) $(RESULT)

