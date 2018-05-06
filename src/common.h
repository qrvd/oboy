#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>
typedef uint8_t byte;
typedef int8_t ibyte;
typedef uint16_t word;

word makeWord(byte upper, byte lower);
long sizeFile(const char *path);
long readNumber(char *string);
long readHexNumber(char *string);
void readBytes(const char *path, void *buffer, size_t bufferSize);

#endif