CFLAGS = -Wall -Wextra -pthread

all: sum_serial sum_multi-thread

sum_serial: sum_serial.c
	gcc $(CFLAGS) -o $@ $<

sum_multi-thread: sum_multi-thread.c
	gcc $(CFLAGS) -o $@ $<

clean:
	rm -f sum_serial sum_multi-thread