#include <stdint.h>
#include <sys/types.h>
#include "../libs/vgaColor.h"

uint8_t vgaEntryColor(vgaColor_t fg, vgaColor_t bg) {
	return fg | bg << 4;
}

uint16_t vgaEntry(unsigned char uc, uint8_t color) {
	return (uint16_t)uc | (uint16_t)color << 8;
}

size_t strlen(char *str) {
	size_t len = 0;
	while (str[len]) len++;

	return len;
}
