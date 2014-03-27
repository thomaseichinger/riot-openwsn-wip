#ifndef __RES_H
#define __RES_H

/**
\addtogroup MAChigh
\{
\addtogroup RES
\{
*/
#include "opentimers.h"

//=========================== define ==========================================

//=========================== typedef =========================================

//=========================== module variables ================================

typedef struct {
   uint16_t        periodMaintenance;
   bool            busySendingKa;        // TRUE when busy sending a keep-alive
   bool            busySendingAdv;       // TRUE when busy sending an advertisement
   uint8_t         dsn;                  // current data sequence number
   uint8_t         MacMgtTaskCounter;    // counter to determine what management task to do
   opentimer_id_t  timerId;
} res_vars_t;

//=========================== prototypes ======================================

void    res_init(void);
uint8_t    debugPrint_myDAGrank(void); // TODO: was bool but complained "conflicting types"
// from upper layer
owerror_t res_send(OpenQueueEntry_t *msg);
// from lower layer
void    task_resNotifSendDone(void);
void    task_resNotifReceive(void);

/**
\}
\}
*/

#endif