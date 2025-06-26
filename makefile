CC = gcc
oCC = @gcc

CFLAGS = -I./include -Wall 
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32

SRC = $(patsubst %.c, %.o, $(wildcard src/*.c))
ObjectSrc = $(patsubst %.c, %.o, $(wildcard src/objects/*.c))
Shaders = $(patsubst %.c, %.o, $(wildcard Shaders/*.c))

Project_Dirs = $(SRC) $(ObjectSrc) $(Shaders) 

NAME_OUTPUT = -o bin/App


all: build clean

%.o: %.c 
	$(oCC) -c $(CFLAGS) $^ -o $@

build: $(Project_Dirs)
	$(CC)  $^ $(LDFLAGS)   $(NAME_OUTPUT) 





.PHONY: clean

clean:
	@find . -type f -name '*.o' -delete