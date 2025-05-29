// qp_config.h - QP/C Configuration Header (Required)
#ifndef QP_CONFIG_H
#define QP_CONFIG_H

// QP configuration macros
#define QP_API_VERSION 0 // QP API version

// Active Object configuration
#define QF_MAX_ACTIVE 8U    // Max number of active objects
#define QF_MAX_TICK_RATE 2U // Max number of system tick rates
#define QF_MAX_EPOOL 3U     // Max number of event pools

// Event and Memory Pool sizing
#define QF_EVENT_SIZ_SIZE 2U   // Size of event size (1, 2, or 4 bytes)
#define QF_EQUEUE_CTR_SIZE 1U  // Size of event queue counters
#define QF_MPOOL_SIZ_SIZE 2U   // Size of memory pool size
#define QF_MPOOL_CTR_SIZE 2U   // Size of memory pool counters
#define QF_TIMEEVT_CTR_SIZE 2U // Size of time event counters

#endif // QP_CONFIG_H