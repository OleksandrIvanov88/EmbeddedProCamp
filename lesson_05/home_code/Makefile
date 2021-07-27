

CXX := gcc
CSTD := c99
CXXFLAGS := -g -o3 -std=$(CSTD) -Wall -Wextra -Wpedantic
CFLAGS := -I$(INCLUDE_DIR)

TARGET := main

INCLUDE_DIR := inc
SOURCE_DIR := src
OBJ_DIR := src/obj



_INCLUDES = domain_logic.h input_processor.h output_processor.h type.h
INCLUDES = $(patsubst %,$(INCLUDE_DIR)/%,$(_INCLUDES))

_OBJ = domain_logic.o input_processor.o output_processor.o main.o
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))


.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.c $(INCLUDES)
	$(CXX) $(CXXFLAGS) -c -o $@ $< $(CFLAGS)

#remove build artifacts
.PHONY: clean 
clean:
		@echo Cleaning Up...
		-rm -fr $(TARGET) 2>/dev/null 
		-rm -fr $(TARGET).exe 2>/dev/null 
		-rm -fr *.o 2>/dev/null 
		-rm -f $(OBJ_DIR)/*.o 2>/dev/null			

.PHONY: run
run:
		./$(TARGET)	

.PHONY: gdb
gdb:
		gdb ./$(TARGET)		


CPPCHECK := cppcheck
override CPPCHECKFLAGS += --language=c --std=c99 --enable=all	

# Static code analysis tool for the C and C++
cppcheck:
	@$(CPPCHECK) $(CPPCHECKFLAGS) $(SOURCES) $(INCLUDES) 


