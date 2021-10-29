#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum cgLogType
{
	cgLogTypeTrace,
	cgLogTypeDebug,
	cgLogTypeInfo,
	cgLogTypeWarning,
	cgLogTypeError,
	cgLogTypeFatal,
} cgLogType;

void cgLogSetFile(FILE * file);

void cgLogSetLevel(cgLogType level);

void cgLogSetQuiet(bool enable);

void cgLogUseColors(bool enable);

void cgLog(cgLogType level, const char * file, int line, const char * format, ...);

#define cgLogTrace(...) cgLog(cgLogTypeTrace, __FILE__, __LINE__, __VA_ARGS__)
#define cgLogDebug(...) cgLog(cgLogTypeDebug, __FILE__, __LINE__, __VA_ARGS__)
#define cgLogInfo(...) cgLog(cgLogTypeInfo,  __FILE__, __LINE__, __VA_ARGS__)
#define cgLogWarning(...) cgLog(cgLogTypeWarning,  __FILE__, __LINE__, __VA_ARGS__)
#define cgLogError(...) cgLog(cgLogTypeError, __FILE__, __LINE__, __VA_ARGS__)
#define cgLogFatal(...) cgLog(cgLogTypeFatal, __FILE__, __LINE__, __VA_ARGS__)
