# Project Configuration
PROJECT_NAME = App
CC = gcc
CFLAGS = -I./include -Wall -Wextra -std=c99 -g
LDFLAGS = -Llibs -lglfw3dll -lglfw3 -lopengl32

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = $(BIN_DIR)/objects
INCLUDE_DIR = include

# Find all C files recursively
C_FILES = $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(C_FILES)))
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

# Create necessary directories
$(shell mkdir -p $(OBJ_DIR))

# Default target
all: $(TARGET)

# Development workflow
dev: clean $(TARGET) run

# Production build
prod: CFLAGS += -O2 -DNDEBUG
prod: clean $(TARGET)

# Debug build
debug: CFLAGS += -DDEBUG -O0
debug: clean $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJ_FILES)
	@echo "Linking $@..."
	@$(CC) $^ $(LDFLAGS) -o $@
	@echo "Build complete: $@"

# Compile C files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@echo "Compiling $<..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/*/%.c
	@echo "Compiling $<..."
	@$(CC) -c $(CFLAGS) $< -o $@


# Clean build artifacts
clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ_DIR)/*.o $(TARGET) 2>/dev/null || true

# Run the application
run: $(TARGET)
	@echo "Running $(PROJECT_NAME)..."
	@./$(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all     - Build the project (default)"
	@echo "  dev     - Clean, build, and run (development)"
	@echo "  prod    - Production build with optimizations"
	@echo "  debug   - Debug build with debug symbols"
	@echo "  clean   - Remove build artifacts"
	@echo "  run     - Run the application"
	@echo "  help    - Show this help message"

# Install dependencies (if needed)
install-deps:
	@echo "Install GLFW and other dependencies manually"

# Show project info
info:
	@echo "Project: $(PROJECT_NAME)"
	@echo "Source files: $(words $(C_FILES)) files"
	@echo "Object files: $(OBJ_FILES)"
	@echo "Compiler: $(CC)"
	@echo "Flags: $(CFLAGS)"

.PHONY: all dev prod debug clean run help install-deps info