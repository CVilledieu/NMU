CC = gcc

CFLAGS = -I./include -Wall 
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32


SRCd = ./src
DEPd = $(SRCd)/depend


SRC = $(patsubst %.c, %.o, $(wildcard $(SRCd)/*.c))

NAME_OUTPUT = -o bin/App


all: build clean

%.o: %.c 
	$(CC) -c $(CFLAGS) $^ -o $@

build: $(SRC)
	$(CC)  $^ $(LDFLAGS)   $(NAME_OUTPUT) 





.PHONY: clean

clean:
	rm -rf $(SRCd)/*.o 