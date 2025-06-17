CC = gcc

CFLAGS = -I./include -Wall 
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32


SRCd = ./src
DEPd = $(SRCd)/depend


SRC = $(patsubst %.c, %.o, $(wildcard $(SRCd)/*.c))
SHD = $(patsubst %.c, %.o, $(wildcard shaders/*.c))

PROJ = $(SRC) $(SHD)

NAME_OUTPUT = -o bin/App


all: build clean

%.o: %.c 
	$(CC) -c $(CFLAGS) $^ -o $@

build: $(PROJ)
	$(CC)  $^ $(LDFLAGS)   $(NAME_OUTPUT) 





.PHONY: clean

clean:
	rm -rf $(SRCd)/*.o 