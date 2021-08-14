CC = gcc
CFLAGS = -g -Wall -Wextra
SRC_DIR = src/
OBJ_DIR = bin/obj/
EXEC_DIR = bin/
NAME = la
TARGET = out

#### DO NOT EDIT BELOW THIS LINE ####

BUILD = $(EXEC_DIR)$(NAME).$(TARGET)
SRCS := $(wildcard src/**/**.c) $(wildcard src/*.c)
OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(OBJS)
	@echo [INFO] Creating Binary Executable [$(TARGET)]
	@$(CC) -o $(BUILD) $^
	@echo [INFO] [$(NAME).$(TARGET)] Created!

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo [CC] $<
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $< -c -o $@

run: all
	@echo [RUNNING]
	@$(EXEC_DIR)./$(NAME).$(TARGET)
	@echo [DONE]

.PHONY: clean
clean:
	@echo [CLEANING OBJECTS]
	@rm -rf $(OBJ_DIR)*.o
	@rm -rf $(OBJ_DIR)**/**.o
	@echo [CLEANING EXECUTABLES]
	@rm $(BUILD)
