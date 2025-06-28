CC = @gcc

CFLAGS = -I./include -Wall 
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32

objDir = ./bin/objects

SRC_Dir = $(patsubst %.c, %.o, $(wildcard src/*.c))
Object_Dir = $(patsubst %.c, %.o, $(wildcard src/objects/*.c))
States_Dir = $(patsubst %.c, %.o, $(wildcard src/states/*.c))
Shaders_Dir = $(patsubst %.c, %.o, $(wildcard Shaders/*.c))
AllSub_Dir = $(patsubst %.c, %.o, $(wildcard src/*/*.c))

Project_Dirs = $(SRC_Dir) $(AllSub_Dir)  $(Shaders_Dir) 

NAME_OUTPUT = -o bin/App


all: build clean


$(objDir)/%.o: %.c 
	$(CC) -c $(CFLAGS) $^ -o $@

build: $(Project_Dirs)
	$(CC)  $^ $(LDFLAGS)   $(NAME_OUTPUT) 





.PHONY: clean

clean:
	@find . -type f -name '*.o' -delete