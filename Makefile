
AR	= ar
CC	= gcc

CFLAGS	= -Wall -g
LDFLAGS	= -L. -lpthread_compat -pthread

PROGS	= libpthread_compat.a
LIBOBJ	= pthread_win32.o pthread_barrier.o

all: $(PROGS)

%.o: %.c %.h
	$(CC) -c $(CFLAGS) $<

libpthread_compat.a: pthread_compat.h $(LIBOBJ)
	$(AR) rc $@ $(LIBOBJ)

clean:
	rm -f *.o $(PROGS)
