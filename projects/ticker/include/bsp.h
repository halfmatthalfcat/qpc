#ifndef BSP_H
#define BSP_H

#include "qpc.h"

#define BSP_TICKS_PER_SEC 100U

void BSP_init(void);
void BSP_terminate(int16_t result);

void QF_onStartup(void);
void QF_onCleanup(void);
void QF_onClockTick(void);

void Q_onError(char const *const module, int_t const id);

#endif // BSP_H