#include <stdio.h>

const unsigned char in[] = "\x49\x27\x6d\x20\x6b\x69\x6c\x6c\x69\x6e\x67\x20\x79\x6f\x75\x72\x20\x62\x72\x61\x69\x6e\x20\x6c\x69\x6b\x65\x20\x61\x20\x70\x6f\x69\x73\x6f\x6e\x6f\x75\x73\x20\x6d\x75\x73\x68\x72\x6f\x6f\x6d";

const char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

void hex_to_base64()
{
	for (size_t i = 0; i+3 < sizeof(in); i+=3) {
		size_t f = in[i] >> 2;
		/* 2 bits from first, 4 bits from 2nd */
		size_t s = ((in[i] & 0x03) << 4) | (in[i+1] >> 4);
		/* 4 bits from second, 2 bits from last */
		size_t t = ((in[i+1] & 0x0f) << 2) | ((in[i+2] & 0xc0) >> 6);
		/* Last 6 bits */
		size_t fth = in[i+2] & 0x3f;
		printf("%c%c%c%c", b64[f], b64[s], b64[t], b64[fth]);
	}
	printf("\n");
}

int main(void)
{
	hex_to_base64();
	return 0;
}
