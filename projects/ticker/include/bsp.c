#include <stdio.h>
#include <stdlib.h>
#include "qpc.h"
#include "safe_std.h"

void BSP_init(void)
{
  printf("QPC_Euchre Started");
}

void BSP_terminate(int16_t result)
{
  (void)result;
  printf("QPC_Euchre Ended");
  exit(0);
}

void QF_onStartup(void) {}
void QF_onCleanup(void) {}
void QF_onClockTick(void)
{
  QTIMEEVT_TICK_X(0U, (void *)0); // clock tick processing
}
Q_NORETURN Q_onError(char const *const module, int_t const id)
{
  FPRINTF_S(stderr, "ERROR in %s:%d", module, id);
  exit(-1);
}