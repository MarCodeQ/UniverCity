inputs := $(wildcard *.c)
outputs := $(inputs:.c=)

all: $(outputs)

$(outputs): %: %.c
	gcc $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf
