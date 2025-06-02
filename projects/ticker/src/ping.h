#ifndef PING_H
#define PING_H

#include "qpc.h"

enum PingSignals
{
  PING_SIG = Q_USER_SIG,
  TIMEOUT_SIG,
  MAX_PING_SIG
};

typedef struct
{
  QActive super;
  QTimeEvt timeEvt;
  uint32_t counter;
} PingCounter;

extern QActive *const AO_PingCounter;

void PingCounter_ctor(void);
void PingCounter_start(uint_fast8_t prio);

#endif // PING_H