#pragma once

#define LOG_PLANT 0x1
#define LOG_SYMBOLS 0x2
#define LOG_STRUCTURE 0x4
#define LOG_LITERALS 0x8
#define LOG_MEMORY 0x10

#define BT_SIZE(n) (((n >> 2) & 0xF) +1 )
#define BT_MODE(n) ((n >> 6) & 0x3)
#define BT_PTR_TO(n) (n & 0x3)
#define BT_NOTDEF(n) ((n &0x2000) == 0x2000)

#define BT_IMPORT 0x8000
#define BT_EXPORT 0x4000

#define BT_IS_IMPORT(n) ((n & BT_IMPORT) == BT_IMPORT)
#define BT_IS_EXPORT(n) ((n & BT_EXPORT) == BT_EXPORT)

void set_logging(int);
void import_module(char *);