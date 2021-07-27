

CXX := gcc
CSTD := c99
CXXFLAGS := -g -o3 -std=$(CSTD) -Wall -Wextra -Wpedantic

TARGET := main

SOURCE_DIR := src
INCLUDE_DIR := inc

.PHONY: all
all: $(TARGET)

#remove build artifacts
.PHONY: clean 
clean:
		@echo Cleaning Up...
		-rm -fr $(TARGET) 2>/dev/null 
		-rm -fr $(TARGET).exe 2>/dev/null 
		-rm -fr *.o 2>/dev/null 			

.PHONY: run
run:
		./$(TARGET)	

.PHONY: gdb
gdb:
		gdb ./$(TARGET)		

 

input_processor.o : $(SOURCE_DIR)/input_processor.c $(INCLUDE_DIR)/input_processor.h 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/input_processor.c -o $@

output_processor.o : $(SOURCE_DIR)/output_processor.c $(INCLUDE_DIR)/output_processor.h 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/output_processor.c -o $@

domain_logic.o : $(SOURCE_DIR)/domain_logic.c $(INCLUDE_DIR)/domain_logic.h   
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/domain_logic.c -o $@

main.o : $(SOURCE_DIR)/main.o 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_DIR)/main.c -o $@


#Target executable
$(TARGET):	output_processor.o domain_logic.o input_processor.o main.o
			$(CC) $(CFLAGS) -L output_processor.o domain_logic.o input_processor.o main.o -o $@	


CPPCHECK := cppcheck
override CPPCHECKFLAGS += --language=c --std=c99 --enable=all	

# Static code analysis tool for the C and C++
cppcheck:
	@$(CPPCHECK) $(CPPCHECKFLAGS) $(SOURCES) $(INCLUDES) 


	
