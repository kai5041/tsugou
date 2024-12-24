PROJECT := prm

SRC_DIR := src
SRC := $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJ_DIR := obj
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

CXX_FLAGS = --std=c++17 -O2 -Wall -Wextra -Iinclude

BUILD_DIR := build
TARGET := $(BUILD_DIR)/$(PROJECT)

$(TARGET): $(OBJ) $(shell find include -type f -name "*.hpp")
	@ mkdir -p $(BUILD_DIR)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@ mkdir -p $(OBJ_DIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

run: $(TARGET)
	@ ./$(TARGET)

install: $(TARGET)
	@ cp $(TARGET) /usr/local/bin
