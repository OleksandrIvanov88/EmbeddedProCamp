
CC := gcc
CSTD := c99
CFLAGS := -g -o3 -std=$(CSTD) -Wall -Wextra -Wpedantic
 
TARGET := main
SRCS := $(TARGET).c input_processor.c output_processor.c domain_logic.c	 	
INCLUDES := input_processor.h output_processor.h domain_logic.h type.h

.PHONY: all
all: $(TARGET)

#Target executable
$(TARGET):	$(SRCS) $(INCLUDES)
			$(CC) $(CFLAGS) $^ -o $@	


CPPCHECK := cppcheck
override CPPCHECKFLAGS += --language=c --std=c99 --enable=all	

# Static code analysis tool for the C and C++
cppcheck:
	@$(CPPCHECK) $(CPPCHECKFLAGS) $(SOURCES) $(INCLUDES) 

#remove build artifacts
.PHONY: clean 
clean:
		@echo Cleaning Up...
		-rm -f $(TARGET) 2>/dev/null 
		-rm -f $(TARGET).exe 2>/dev/null 			

.PHONY: run
run:
		./$(TARGET)	

.PHONY: gdb
gdb:
		gdb ./$(TARGET)			
