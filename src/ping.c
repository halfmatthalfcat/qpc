#include "ping.h"
#include "bsp.h"
#include <stdio.h>

static PingCounter l_pingCounter;

static QEvt const *l_pingCounterQueueSto[10];

QActive *const AO_PingCounter = &l_pingCounter.super;

static QState PingCounter_initial(PingCounter *const me, void const *const par);
static QState PingCounter_active(PingCounter *const me, QEvt const *const e);

void PingCounter_ctor(void)
{
  PingCounter *const me = &l_pingCounter;
  QActive_ctor(&me->super, Q_STATE_CAST(&PingCounter_initial));
  QTimeEvt_ctorX(&me->timeEvt, &me->super, TIMEOUT_SIG, 0U);
  me->counter = 0U;
}

static QState PingCounter_initial(PingCounter *const me, void const *const par)
{
  (void)par;

  QTimeEvt_armX(&me->timeEvt, BSP_TICKS_PER_SEC, BSP_TICKS_PER_SEC);

  return Q_TRAN(&PingCounter_active);
}

static QState PingCounter_active(PingCounter *const me, QEvt const *const e)
{
  QState status;

  switch (e->sig)
  {
  case PING_SIG:
    ++me->counter;
    printf("%u", me->counter);
    fflush(stdout);
    status = Q_HANDLED();
    break;
  case TIMEOUT_SIG:
    static QEvt const pingEvt = {PING_SIG, 0U, 0U};
    QACTIVE_POST(&me->super, &pingEvt, &me->super);
    status = Q_HANDLED();
    break;
  default:
    status = Q_SUPER(&QHsm_top);
    break;
  }

  return status;
}

void PingCounter_start(uint_fast8_t prio)
{
  QACTIVE_START(AO_PingCounter,
                prio,
                l_pingCounterQueueSto,
                Q_DIM(l_pingCounterQueueSto),
                (void *)0, 0U, (void *)0);
}