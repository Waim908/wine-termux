/* Automatically generated by make depend; DO NOT EDIT!! */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_capture(void);
extern void func_dependency(void);
extern void func_mmdevenum(void);
extern void func_propstore(void);
extern void func_render(void);
extern void func_spatialaudio(void);

const struct test winetest_testlist[] =
{
    { "capture", func_capture },
    { "dependency", func_dependency },
    { "mmdevenum", func_mmdevenum },
    { "propstore", func_propstore },
    { "render", func_render },
    { "spatialaudio", func_spatialaudio },
    { 0, 0 }
};
