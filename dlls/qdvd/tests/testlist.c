/* Automatically generated by make depend; DO NOT EDIT!! */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_graph(void);
extern void func_navigator(void);

const struct test winetest_testlist[] =
{
    { "graph", func_graph },
    { "navigator", func_navigator },
    { 0, 0 }
};