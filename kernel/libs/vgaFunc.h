#pragma once
#include <stdint.h>
#include <sys/types.h>
#include "vgaColor.h"
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

uint8_t vgaEntryColor(vgaColor_t fg, vgaColor_t bg);
uint16_t vgaEntry(unsigned char uc, uint8_t color);
size_t strlen(char *str);
