/* Automatically generated by make depend; DO NOT EDIT!! */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_asmcache(void);
extern void func_asmenum(void);
extern void func_asmname(void);
extern void func_fusion(void);

const struct test winetest_testlist[] =
{
    { "asmcache", func_asmcache },
    { "asmenum", func_asmenum },
    { "asmname", func_asmname },
    { "fusion", func_fusion },
    { 0, 0 }
};