#ifndef __UDPPRINT_H
#define __UDPPRINT_H

/**
\addtogroup AppUdp
\{
\addtogroup udpPrint
\{
*/

//=========================== define ==========================================

//=========================== typedef =========================================

//=========================== variables =======================================

//=========================== prototypes ======================================

void udpprint_init(void);
void udpprint_sendDone(OpenQueueEntry_t* msg, owerror_t error);
void udpprint_receive(OpenQueueEntry_t* msg);
bool udpprint_debugPrint(void);

/**
\}
\}
*/

#endif
