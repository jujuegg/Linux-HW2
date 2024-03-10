CC = gcc
CFLAGS = -O1 -g -Wall


OBJS := main.o bt.o

all: postorder

postorder: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ -lm

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c -MMD -MF .$@.d $<

clean:
	rm -f $(OBJS)
	rm -f *.dSYM
	rm -f postorder
	rm -f .*.o.d
