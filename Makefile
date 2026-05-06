CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET   = hangman
SRC      = hangman.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all clean
