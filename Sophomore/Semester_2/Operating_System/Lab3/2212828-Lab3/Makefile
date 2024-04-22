inputs := $(wildcard *.c)
outputs := $(inputs:.c=)

all: $(outputs)

$(outputs): %: %.c
	g++ $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf
