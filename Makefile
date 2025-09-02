# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -O2

# Source and build setup
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
TARGET := app

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Convenience run target
run: $(TARGET)
	./$(TARGET)
