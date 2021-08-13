CC = gcc
CFLAGS = -g -Wall -Wextra
OBJ_DIR = bin/obj
EXEC_DIR = bin/
NAME = la.out
BUILD = $(EXEC_DIR)$(NAME)

SRCS := $(shell find . -name "*.c")

all: $(SRCS)
	$(CC) $(SRCS) -o $(BUILD)

run: all
	$(BUILD)
