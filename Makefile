# all: sw_doge

CC = g++
CFLAGS = -g -Wall
LIB = -pthread
INC_FLAGS = -Iinclude
BUILD_DIR = .build
SRC_DIR = src
SRC_EXT = cpp

SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))
TARGET = bin/sw_doge

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(INC_FLAGS) $(LIB) -o $@


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR): 
	@mkdir -p $@

clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: $(BUILD_DIR) clean 

VPATH = src include