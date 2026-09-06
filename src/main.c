#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char builtinListe[][10] = {"echo", "exite", "type"};

int main(int argc, char *argv[])
{
  char eingabe[100];

  // Flush after every printf
  setbuf(stdout, NULL);

  while (1)
  {
    printf("$ ");

    fgets(eingabe, 100, stdin);

    // Wait for user input
    char input[100];
    fgets(input, 100, stdin);

    // Remove the trailing newline
    input[strlen(input) - 1] = '\0';

    // COMMAND: exit
    // strcmp: string comparison. if equal, return 0
    if (strcmp(input, "exit") == 0)
    {
      break;
    }
    else if (strncmp(input, "echo ", 5) == 0) // COMMAND: echo
    {
      printf("%s\n", input + 5);
    }
    else
    {
      printf("%s: command not found\n", input);
    }
  }
  return 0;
}
