TARGET = exercises
SRC = main.c exercises.c
BUILD_DIR = build
OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -g

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all run clean
