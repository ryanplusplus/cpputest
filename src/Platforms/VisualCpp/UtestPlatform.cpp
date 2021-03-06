#include "Platform.h"
#include <stdlib.h>
#include "CppUTest/TestHarness.h"
#undef malloc
#undef free
#undef calloc
#undef realloc

#include <stdio.h>
#include <stdarg.h>
#include <setjmp.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include "CppUTest/PlatformSpecificFunctions.h"

#include <windows.h>
#include <mmsystem.h>


#include <setjmp.h>

static jmp_buf test_exit_jmp_buf[10];
static int jmp_buf_index = 0;

int PlatformSpecificSetJmp(void (*function) (void* data), void* data)
{
    if (0 == setjmp(test_exit_jmp_buf[jmp_buf_index])) {
        jmp_buf_index++;
        function(data);
        jmp_buf_index--;
        return 1;
    }
    return 0;
}

void PlatformSpecificLongJmp()
{
    jmp_buf_index--;
    longjmp(test_exit_jmp_buf[jmp_buf_index], 1);
}

void PlatformSpecificRestoreJumpBuffer()
{
    jmp_buf_index--;
}

void PlatformSpecificRunTestInASeperateProcess(UtestShell* shell, TestPlugin* plugin, TestResult* result)
{
   printf("-p doesn't work on this platform as it is not implemented. Running inside the process\b");
   shell->runOneTest(plugin, *result);
}

TestOutput::WorkingEnvironment PlatformSpecificGetWorkingEnvironment()
{
    return TestOutput::vistualStudio;
}

///////////// Time in millis

static long TimeInMillisImplementation()
{
    return timeGetTime();
}

long (*GetPlatformSpecificTimeInMillis)() = TimeInMillisImplementation;

///////////// Time in String

static const char* TimeStringImplementation()
{
    time_t the_time = time(NULL);
    struct tm the_local_time;
    static char dateTime[80];
    localtime_s(&the_local_time, &the_time);
    strftime(dateTime, 80, "%Y-%m-%dT%H:%M:%S", &the_local_time);
    return dateTime;
}

const char* (*GetPlatformSpecificTimeString)() = TimeStringImplementation;

////// taken from gcc

int PlatformSpecificVSNprintf(char *str, size_t size, const char* format, va_list args)
{
    char* buf = 0;
    size_t sizeGuess = size;

    int result = _vsnprintf_s( str, size, _TRUNCATE, format, args);
    str[size-1] = 0;
    while (result == -1)
    {
        if (buf != 0)
            free(buf);
        sizeGuess += 10;
        buf = (char*)malloc(sizeGuess);
        result = _vsnprintf_s( buf, sizeGuess, _TRUNCATE, format, args);
    }

    if (buf != 0)
        free(buf);
    return result;

}

PlatformSpecificFile PlatformSpecificFOpen(const char* filename, const char* flag)
{
   FILE* file;
   fopen_s(&file, filename, flag);
   return file;
}

void PlatformSpecificFPuts(const char* str, PlatformSpecificFile file)
{
   fputs(str, (FILE*)file);
}

void PlatformSpecificFClose(PlatformSpecificFile file)
{
   fclose((FILE*)file);
}

void PlatformSpecificFlush()
{
  fflush(stdout);
}

int PlatformSpecificPutchar(int c)
{
  return putchar(c);
}

void* PlatformSpecificMalloc(size_t size)
{
   return malloc(size);
}

void* PlatformSpecificRealloc (void* memory, size_t size)
{
   return realloc(memory, size);
}

void PlatformSpecificFree(void* memory)
{
   free(memory);
}

void* PlatformSpecificMemCpy(void* s1, const void* s2, size_t size)
{
   return memcpy(s1, s2, size);
}

void* PlatformSpecificMemset(void* mem, int c, size_t size)
{
    return memset(mem, c, size);
}

double PlatformSpecificFabs(double d)
{
   return fabs(d);
}

extern "C" int (*PlatformSpecificIsNan)(double) = _isnan;

int PlatformSpecificVSNprintf(char *str, unsigned int size, const char* format, void* args)
{
   return _vsnprintf_s( str, size, _TRUNCATE, format, (va_list) args);
}

static PlatformSpecificMutex DummyMutexCreate(void)
{
    FAIL("PlatformSpecificMutexCreate is not implemented");
    return 0;
}

static void DummyMutexLock(PlatformSpecificMutex mtx)
{
    FAIL("PlatformSpecificMutexLock is not implemented");
}

static void DummyMutexUnlock(PlatformSpecificMutex mtx)
{
    FAIL("PlatformSpecificMutexUnlock is not implemented");
}

static void DummyMutexDestroy(PlatformSpecificMutex mtx)
{
    FAIL("PlatformSpecificMutexDestroy is not implemented");
}

PlatformSpecificMutex (*PlatformSpecificMutexCreate)(void) = DummyMutexCreate;
void (*PlatformSpecificMutexLock)(PlatformSpecificMutex) = DummyMutexLock;
void (*PlatformSpecificMutexUnlock)(PlatformSpecificMutex) = DummyMutexUnlock;
void (*PlatformSpecificMutexDestroy)(PlatformSpecificMutex) = DummyMutexDestroy;

