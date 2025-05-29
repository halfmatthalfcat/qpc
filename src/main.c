#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  const char *msg[] = {"Hello", "C", "World", "from", "VS Code", "and the C extension!"};
  size_t msg_count = sizeof(msg) / sizeof(msg[0]);

  for (size_t i = 0; i < msg_count; i++)
  {
    printf("%s ", msg[i]);
  }
  printf("\n");

  return 0;
}