#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bsp.h"
#include "ping.h"

int main(void)
{
  BSP_init();

  QF_init();

  PingCounter_ctor();

  PingCounter_start(1U);

  return QF_run();
}