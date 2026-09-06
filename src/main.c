#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of shell biuld-in commands
char builtinList[][10] = {"echo", "exit", "type"};

int main(int argc, char *argv[])
{
  char input[100];

  // Flush after every printf
  setbuf(stdout, NULL);

  while (1)
  {
    printf("$ ");

    fgets(input, 100, stdin);

    // memcmp compare two data type byte by byte, and the
    // number of bytes to compare

    if (memcmp(input, "exit", 4) == 0)
    {
      return 0;
    }
    else if (memcmp(input, "echo", 4) == 0)
    {
      printf("%s", &input[5]);
    }
    else if (memcmp(input, "type", 4) == 0)
    {
      char *parameter = &input[5];
      int n = lineLength(parameter);
      parameter[n] = '\0';
      printf("%s", parameter);

      int isBuiltin = 0;
      int isExecutable = 0;
      int isUnknown = 1;

      // sizeof(builtinList)/sizeof(builtinList[0]) gives the vector length. Used it before, on other project
      for (int i = 0; i < sizeof(builtinList) / sizeof(builtinList[0]); i++)
      {
        if (memcmp(parameter, builtinList[i], stringLength(builtinList[i])) == 0)
        {
          isBuiltin = 1;
          isUnknown = 0;
        }
      }
      if (isBuiltin != 0)
      {
        printf(" is a shell builtin \n");
      }
      else if (isExecutable != 0)
      {
        printf("is an executable \n");
      }
      else if (isUnknown != 0)
      {
        printf(": not found \n");
      }
    }
    else
    {
      int n = lineLength(input);
      input[n] = '\0';
      printf(input);
      printf(": command not found\n");
    }
  }

  return 0;
}
int stringLength(char *string)
{
  if (string == NULL)
  {
    return -1;
  }
  int result = 0;

  while (string[result] != '\0')
  {
    ++result;
  }
  return result;
}
int lineLength(char *string)
{
  if (string == NULL)
  {
    return -1;
  }
  int result = 0;

  while ((string[result] != '\0') && (string[result] != '\n'))
  {
    ++result;
  }
  return result;
}