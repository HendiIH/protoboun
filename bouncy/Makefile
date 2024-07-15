CC=gcc
CFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11
EXEC=bouncy

# List of all source files
SRCS=bouncy.c player.c screen.c envitem.c camera.c enemy.c

# Derive object files from source files
OBJS=$(SRCS:.c=.o)

# Main target
$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

# Compile source files to object files
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# Clean target
clean:
	rm -rf $(EXEC) $(OBJS)
