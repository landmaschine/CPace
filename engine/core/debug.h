#pragma once
#include "stdio.h"

void printErr(const char* msg, const char* file, const int line);

#define LOGERR(msg) printErr(msg, __FILE__, __LINE__)