#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
#include "osek_os.h"

/* #####################  TASK  ########################## */
#define cfgOSEK_TASK_NUM 1
extern const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM];
extern const BOOL   OsekTaskAuotStartable[cfgOSEK_TASK_NUM];
#define ID_vTask0		 (MIN_TSKID+0)
extern TASK(vTask0);
/* #####################  EVENT ########################## */
#define cfgOSEK_EVENTFLAG_NUM 0
/* #####################  ALARM ########################## */
#define cfgOSEK_ALARM_NUM 1
extern ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
extern UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
extern const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM];
#define ID_vAlarm0		(0)
extern ALARMCALLBACK(vAlarm0);
/*  ####################  RESOURCE ####################### */
#define cfgOSEK_RESOURCE_NUM 1
extern const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM];
#define ID_vRes0		 (MIN_MTXID+0)
#endif /* _OSEK_CFG_H_ */
