#include "debug.h"

void printErr(const char* msg, const char* file, const int line) {
    fprintf(stderr, msg, "\n");
    fprintf(stderr, "  %s  : line: %d\n", file, line);
}