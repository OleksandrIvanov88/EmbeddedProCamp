
CC := gcc
CSTD := c99
CFLAGS := -g -o3 -std=$(CSTD) -Wall -Wextra -Wpedantic
#LDFLAGS

#INCLUDES = 
TARGET_NAME := prg_lang
SRCS := $(TARGET_NAME).c	
TARGET := $(TARGET_NAME)
OBJS := $(SRCS:.c=.o)
CPP := $(SRCS:.c=.i)

.PHONY: all
all: $(TARGET)

#Target executable
$(TARGET):	$(SRCS)
			$(CC) $(CFLAGS) $^ -o $@	

#Target binary
obj: $(OBJS)
$(OBJS): 	$(SRCS)
			$(CC) $(CFLAGS) -c $^ -o $@			

#Target preprocessed
cpp: $(CPP) 
$(CPP):	$(SRCS) 
		$(CC) $(CFLAGS) -E $^ -o $@

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@


#remove build artifacts
.PHONY: clean 
clean:
		@echo Cleaning Up...
		-rm -f $(OBJS) 2>/dev/null $(CPP) 2>/dev/null 	

#remove build artifacts and target
.PHONY: tidy 
tidy: 	clean
		-rm -f $(TARGET) 2>/dev/null 
		-rm -f $(TARGET).exe 2>/dev/null 			

.PHONY: run
run:
		./$(TARGET)	

.PHONY: gdb
gdb:
		gdb ./$(TARGET)			
