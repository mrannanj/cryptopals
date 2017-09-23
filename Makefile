.PHONY: clean

basics/hex_to_base64: basics/hex_to_base64.c
	$(CC) $^ -o $@

clean:
	rm -f basics/hex_to_base64
