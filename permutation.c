#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

char *teststring = "RGBY";
#define LENGTH 5

void process(char *substring)
{
  printf("%s\n", substring);
}

void swap(char *substring, int size, void (*proc)(char*))
{
  int index = --size;
  char temp;
  while (substring[index])
  {
    if (size)
    {
      swap(substring, size, process);
    }
    index++;
    if (substring[index])
    {
      // move our character 1 position right
      temp = substring[index - 1];
      substring[index - 1] = substring[index];
      substring[index] = temp;
      proc(substring);
    }
  }

  // restore the array to its original state
  temp = substring[index - 1];
  for (index--; index > size; index--)
  {
    substring[index] = substring[index - 1];
  }
  substring[index] = temp;
}


int main(int argc, char *argv[])
{
  char *array = (char *)malloc(LENGTH);
  memcpy(array, teststring, LENGTH);
  printf("%s\n", array);
  swap(array, LENGTH - 1, process);
  return (0);
}

