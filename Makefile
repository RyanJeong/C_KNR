# :set noexpandtab
#Tell make to make one .out file for each .cpp file found in the current directory
# all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))
# all: $(patsubst %.c, %.out, $(wildcard *.c))

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
# %.out: %.cpp Makefile
#     g++ $< -o $@ -std=c++0x
# %.out: %.c Makefile
	#gcc -c $< -o $@ -ansi -Wall

#################################################

CC := gcc
CFLAGS := -ansi -Wall
TARGET := a.out

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.c)
# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
OBJS := $(patsubst %.c,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -lm
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clear: find . ! -name *.zip -delete 
