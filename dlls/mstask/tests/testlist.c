/* Automatically generated by make depend; DO NOT EDIT!! */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define STANDALONE
#include "wine/test.h"

extern void func_task(void);
extern void func_task_scheduler(void);
extern void func_task_trigger(void);

const struct test winetest_testlist[] =
{
    { "task", func_task },
    { "task_scheduler", func_task_scheduler },
    { "task_trigger", func_task_trigger },
    { 0, 0 }
};
