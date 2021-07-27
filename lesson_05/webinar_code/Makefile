
CC := gcc
CSTD := c99
CFLAGS := -g -o3 -std=$(CSTD) -Wall -Wextra -Wpedantic

TARGET := main
SRCS := $(TARGET).c domain_logic.c	output_processor.c input_processor.c 


.PHONY: all
all: $(TARGET)

#Target executable
$(TARGET):	$(SRCS)
			$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

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
