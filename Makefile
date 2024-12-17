PROJECT_NAME = prm
BUILD_DIR = build
SRC_DIR = src
HEADER_DIR = include

TARGET = $(BUILD_DIR)/$(PROJECT_NAME)

SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.cpp")
HEADER_FILES = $(shell find $(HEADER_DIR) -type f -name "*.hpp")

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXXFLAGS = -I$(HEADER_DIR) -Wall -Wextra -std=c++17

$(TARGET): $(OBJ_FILES) $(BUILD_DIR)
	$(CXX) -o $(TARGET) $(OBJ_FILES)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

$(BUILD_DIR):
	@ mkdir -p $(BUILD_DIR)

install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/$(PROJECT_NAME)

install-local: $(TARGET) $(OBJ_FILES) $(HEADER_FILES)
	@ mkdir -p $(HOME)/bin
	cp $(TARGET) $(HOME)/bin/$(PROJECT_NAME)
	@ echo "Installed $(PROJECT_NAME) to $(HOME)/bin"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: install install-local clean
