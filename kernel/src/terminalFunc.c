#include "../libs/vgaFunc.h"
#include "../libs/terminalCfg.h"
#include <sys/types.h>
#include <stdint.h>

void terminalInit(terminalCfg_t *t) {
    t->terminalRow = 0;
	t->terminalCol = 0;
	t->terminalColor = vgaEntryColor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	t->terminalBuf = (uint16_t*)0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			t->terminalBuf[index] = vgaEntry(' ', t->terminalColor);
		}
	}
}

void terminalSetColor(terminalCfg_t *t, uint8_t color) {
	t->terminalCol = color;
}

void terminalSetEntry(terminalCfg_t *t, char c) {
	size_t index = t->terminalRow * VGA_WIDTH + t->terminalCol;
	t->terminalBuf[index] = vgaEntry(c, t->terminalColor);
}

void terminalPutChar(terminalCfg_t *t, char c) {
	terminalSetEntry(t, c);
	if (++t->terminalCol == VGA_WIDTH) {
		t->terminalCol = 0;
		if (++t->terminalRow == VGA_HEIGHT) t->terminalRow = 0;
	}
}

void terminalWrite(terminalCfg_t *t, char *data, size_t size) {
	for (size_t i = 0; i < size; i++) terminalPutChar(t, data[i]);
}

void terminalWriteStr(terminalCfg_t *t, char *data) {
	terminalWrite(t, data, strlen(data));
}
