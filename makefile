ifeq ($(OS), Windows_NT)
	INCLUDES := include\\
	BUILD := build\\
	BIN := bin\\
	EXECUTABLE := $(BIN)Tic_Tac_Toe.exe
	SOURCE := source\\
	DELETE := del
else
	INCLUDES := include/
	BUILD := build/
	BIN := bin/
	EXECUTABLE := $(BIN)Tic_Tac_Toe.exe
	SOURCE := source/
	DELETE := rm
endif

CPP := g++
CPPFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Werror

all: $(EXECUTABLE)

$(EXECUTABLE): $(BUILD)main.o $(BUILD)Tic_Tac_Toe.o
	$(CPP) $(CPPFLAGS) $(BUILD)main.o $(BUILD)Tic_Tac_Toe.o  -o $(EXECUTABLE)

$(BUILD)main.o: $(SOURCE)main.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)main.cpp -I$(INCLUDES) -o $(BUILD)main.o

$(BUILD)Tic_Tac_Toe.o: $(SOURCE)Tic_Tac_Toe.cpp
	$(CPP) $(CPPFLAGS) -c $(SOURCE)Tic_Tac_Toe.cpp -I$(INCLUDES) -o $(BUILD)Tic_Tac_Toe.o


clean:

	-$(rm) $(EXECUTABLE)
	-$(rm) $(BUILD)main.o
	-$(rm) $(BUILD)MinimumSpanningTree.o