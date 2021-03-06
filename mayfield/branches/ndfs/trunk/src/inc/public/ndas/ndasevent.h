#ifndef _NDAS_EVENT_H_
#define _NDAS_EVENT_H_

#pragma once
#include "ndastype.h"

/* NDAS Event Version definition */

/*DOM-IGNORE-BEGIN*/
#define NDAS_EVENT_VERSION_MAJOR 0x0002
#define NDAS_EVENT_VERSION_MINOR 0x0000
/*DOM-IGNORE-END*/

typedef WORD NDAS_EVENT_TYPE;

/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_VERSION_INFO                    0x0000
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_DEVICE_STATUS_CHANGED           0x0001
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_LOGICALDEVICE_STATUS_CHANGED    0x0002
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_LOGICALDEVICE_DISCONNECTED      0x0003
/* #define NDAS_EVENT_TYPE_LOGICALDEVICE_RECONNECTING      0x0004 */
/* #define NDAS_EVENT_TYPE_LOGICALDEVICE_RECONNECTED       0x0005 */
/* #define NDAS_EVENT_TYPE_LOGICALDEVICE_EMERGENCY         0x0016 */
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_LOGICALDEVICE_ALARMED           0x0017
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_DEVICE_PROPERTY_CHANGED         0x0006
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_UNITDEVICE_PROPERTY_CHANGED     0x0007
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_DEVICE_ENTRY_CHANGED            0x0011
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_LOGICALDEVICE_ENTRY_CHANGED     0x0012
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_LOGICALDEVICE_PROPERTY_CHANGED  0x0014
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_LOGICALDEVICE_RELATION_CHANGED  0x0015
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_SURRENDER_REQUEST               0x0013
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_SUSPEND_REJECTED                0x0030
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_TERMINATING                     0xFFFF
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_PERIODIC                        0x00FF

/* These event types are only for NDAS USER API DLL */

/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_CONNECTION_FAILED    0xFF01
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_CONNECTING           0xFF02
#define NDAS_EVENT_TYPE_RETRYING_CONNECTION  NDAS_EVENT_TYPE_CONNECTING
/* <COMBINE NDAS_EVENT_TYPE> */
#define NDAS_EVENT_TYPE_CONNECTED            0xFF03

/* Event Messages */

/* 8 byte packing of structures */
#include <pshpack8.h>

typedef struct _NDAS_EVENT_LOGICALDEVICE_INFO
{
	NDAS_LOGICALDEVICE_ID LogicalDeviceId;
	NDAS_LOGICALDEVICE_STATUS OldStatus;
	NDAS_LOGICALDEVICE_STATUS NewStatus;
	ULONG AdapterStatus;
} NDAS_EVENT_LOGICALDEVICE_INFO, *PNDAS_EVENT_LOGICALDEVICE_INFO;

/*DOM-IGNORE-BEGIN*/
C_ASSERT(16 == sizeof(NDAS_EVENT_LOGICALDEVICE_INFO));
/*DOM-IGNORE-END*/

typedef struct _NDAS_EVENT_DEVICE_INFO
{
	DWORD SlotNo;
	NDAS_DEVICE_STATUS OldStatus;
	NDAS_DEVICE_STATUS NewStatus;
} NDAS_EVENT_DEVICE_INFO, *PNDAS_EVENT_DEVICE_INFO;

/*DOM-IGNORE-BEGIN*/
C_ASSERT(12 == sizeof(NDAS_EVENT_DEVICE_INFO));
/*DOM-IGNORE-END*/

typedef struct _NDAS_EVENT_UNITDEVICE_INFO
{
	DWORD SlotNo;
	DWORD UnitNo;
} NDAS_EVENT_UNITDEVICE_INFO, *PNDAS_EVENT_UNITDEVICE_INFO;

/*DOM-IGNORE-BEGIN*/
C_ASSERT(8 == sizeof(NDAS_EVENT_UNITDEVICE_INFO));
/*DOM-IGNORE-END*/

typedef struct _NDAS_EVENT_VERSION_INFO
{
	WORD MajorVersion;
	WORD MinorVersion;
} NDAS_EVENT_VERSION_INFO, *PNDAS_EVENT_VERSION_INFO;

/*DOM-IGNORE-BEGIN*/
C_ASSERT(4 == sizeof(NDAS_EVENT_VERSION_INFO));
/*DOM-IGNORE-END*/

/* <TITLE NDAS Surrender Request Flags> */
#define NDAS_SRF_READ   0x01
/* <COMBINE NDAS_SRF_READ> */
#define NDAS_SRF_WRITE  0x02

typedef struct _NDAS_EVENT_SURRENDER_REQUEST_INFO
{
	DWORD SlotNo;
	DWORD UnitNo;
	DWORD RequestFlags;
	GUID RequestHostGuid;
} NDAS_EVENT_SURRENDER_REQUEST_INFO, *PNDAS_EVENT_SURRENDER_REQUEST_INFO;

/*DOM-IGNORE-BEGIN*/
C_ASSERT(28 == sizeof(NDAS_EVENT_SURRENDER_REQUEST_INFO));
/*DOM-IGNORE-END*/

#include <poppack.h>

#endif /* _NDAS_EVENT_H_ */
