#include "kernel/libs/terminalCfg.h"
#include "kernel/libs/terminalFunc.h"

int main() {
    terminalCfg_t terminalCfg;
    terminalInit(&terminalCfg);
    terminalWriteStr(&terminalCfg, "Hello World!\n");

    return 0;
}
