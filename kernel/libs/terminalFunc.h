#pragma once
#include <sys/types.h>
#include <stdint.h>

typedef struct terminalCfg terminalCfg_t;
void terminalInit(terminalCfg_t *t);
void terminalSetColor(terminalCfg_t *t, uint8_t color);
void terminalSetEntry(terminalCfg_t *t, char c);
void terminalPutChar(terminalCfg_t *t, char c);
void terminalWrite(terminalCfg_t *t, char *data, size_t size);
void terminalWriteStr(terminalCfg_t *t, char *data);
