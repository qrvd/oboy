#include "common.h"
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

word makeWord(byte upper, byte lower) {
  return (word(upper) << 8) | (word(lower));
}

// Calculate the size of a file in bytes.
long sizeFile(const char *path) {
  assert(path);
  FILE *handle = fopen(path, "r");
  assert(handle);

  // SEEK_END is not portable, but this is *probably* the
  // fastest way to size the file.
  fseek(handle, 0, SEEK_END);
  long length = ftell(handle);
  fclose(handle);

  return length;
}

// Read a number from a string and
// make sure to avoid errors.
long readNumber(char *string) {
  errno = 0;
  long n = strtol(string, NULL, 0);
  assert(errno == 0);
  return n;
}

// Read a hex number from a string and
// make sure to avoid errors.
long readHexNumber(char *string) {
  errno = 0;
  long n = strtol(string, NULL, 16);
  assert(errno == 0);
  return n;
}

// Read the bytes of a file into a buffer.
void readBytes(const char *path, void *buffer, size_t bufferSize) {
  size_t size = sizeFile(path);
  assert(buffer);
  assert(size <= bufferSize);

  // Read the file in binary mode, to ensure that no bytes
  // will be skipped on some OSes.
  FILE *handle = fopen(path, "rb");
  size_t read_count = fread(buffer, sizeof(char), size, handle);
  assert(read_count == size);
  fclose(handle);
}