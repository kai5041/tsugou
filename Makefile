PROJECT_NAME := tsu
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

CXX ?= g++
CXX_FLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -MMD -MP
LD_FLAGS ?=

RELEASE_FLAGS ?= -O3 -DNDEBUG -static-libstdc++ -static-libgcc

PLATFORM_NAME ?= linux-x32_64
include toolchains/$(PLATFORM_NAME).mk

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/$(PLATFORM_NAME)/%.o,$(SOURCES))
DEPS := $(OBJECTS:.o=.d)

LIBS ?= $(wildcard ./libs/$(PLATFORM_NAME)/*.a)

all: CXX_FLAGS += -g
all: $(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)

release: CXX_FLAGS += $(RELEASE_FLAGS)
release: clean $(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)

$(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -o $@ $^ $(LIBS) $(LD_FLAGS)

$(BUILD_DIR)/$(PLATFORM_NAME)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

-include $(DEPS)


clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME)

install: release
	sudo cp $(BUILD_DIR)/$(PLATFORM_NAME)/$(PROJECT_NAME) /usr/local/bin/

.PHONY: all release clean run test
