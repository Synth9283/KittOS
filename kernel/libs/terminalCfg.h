#pragma once
#include <sys/types.h>
#include <stdint.h>

typedef struct terminalCfg {
    size_t terminalRow;
    size_t terminalCol;
    uint8_t terminalColor;
    uint16_t *terminalBuf;
} terminalCfg_t;
