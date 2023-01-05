

# Compiler to use
CC=gcc -g

# Flags to pass to the compiler
CFLAGS=-c -Wall

# Name of the executable to create
EXE=push_swap

# List of object files to include in the executable
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

# Directory containing the library files
LIBDIR=./libft

# List of libraries to link with
LIBS=./libft/libft.a

#$(addprefix $(LIBDIR)/,$(wildcard *.a))

# Default target
all: $(EXE)

# Target to create the executable
$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $@

# Target to compile a .c file into a .o file
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Target to clean up temporary files
clean:
	rm -f $(OBJS) $(EXE)
