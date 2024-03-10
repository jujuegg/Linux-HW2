CC = gcc
CFLAGS = -O1 -g -Wall


OBJS := main.o

all: lru

lru: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c -MMD -MF .$@.d $<

clean:
	rm -f $(OBJS)
	rm -f *.dSYM
	rm -f lru
	rm -f .*.o.d
