#include <stdio.h>
#include <limits.h>
#include <ctype.h>

const unsigned char in[] = "\x1b\x37\x37\x33\x31\x36\x3f\x78\x15\x1b\x7f\x2b\x78\x34\x31\x33\x3d\x78\x39\x78\x28\x37\x2d\x36\x3c\x78\x37\x3e\x78\x3a\x39\x3b\x37\x36";
char out[sizeof(in)+1];

void single_byte_xor()
{
	for (unsigned c = 0; c <= UCHAR_MAX; ++c) {
		for (size_t i = 0; i < sizeof(in); ++i) {
			out[i] = in[i] ^ c;
			if (!isprint(out[i]))
				break;
		}
		printf("c: %hhx, s: %s\n", c, out);
next:;
	}
}

int main(void)
{
	single_byte_xor();
}
