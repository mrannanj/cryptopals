.PHONY: clean all

T := basics/hex_to_base64 basics/single_byte_xor

all: $T

basics/hex_to_base64: basics/hex_to_base64.c
	$(CC) $^ -o $@

basics/single_byte_xor: basics/single_byte_xor.c
	$(CC) $^ -o $@

clean:
	rm -f $T
