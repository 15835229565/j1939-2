#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <pthread.h>

#include "config.h"

/*=================================  ���Ͷ��� ==========================================*/
typedef unsigned char                           BOOL;
typedef unsigned char                           UINT8;
typedef char                                    INT8;
typedef unsigned short                          UINT16;
typedef short                                   INT16;
typedef unsigned int                            UINT32;
typedef int                                     INT32;
typedef unsigned long                           UINT64;
typedef long                                    INT64;
typedef double                                  F64;
typedef float                                   F32;
typedef void *                                  VOID_PTR;
typedef void *                                  (*THREAD_FUNC)(void *arg);

#ifndef  NULL
#define  NULL                                   ((void*)0)
#endif

#ifndef false
#define false                                   (0)
#endif
#ifndef true
#define true                                    (!false)
#endif

/*==============================   j1939Э��Ӧ�ò���Ϣ����   ====================================*/

/* GUI��(QT)�ɷ��͵���Ϣ���� */
typedef enum _SENDDED_MSG_TYPE{
    tx_req_addr,
    tx_declare_addr,
    tx_unable_declare_addr,
    tx_req_engine_speed,
    tx_engine_speed
}SENDDED_MSG_TYPE;

/* J1939Ӧ�ò���Ϣ */
typedef struct _MSG{
    INT8  data_length;
    UINT8  dp;
    UINT8  pf;
    UINT8  ps;
    UINT8  p;
    UINT32 pgn;
    UINT8  data[MSG_MAX_LENGTH];
}MSG;

/* GUI��(QT)�������ʱ��ȡ����Ϣ�ṹ */
typedef struct _DTC{
    UINT32 spn;
    UINT8 fmi;
    UINT8 oc;
}DTC;

/* GUI��(QT)���յ���Ϣ�ṹ */
typedef struct _RECVED_MSG{
    F32   engine_speed;           /* engine speed */
    INT32 fule_press;             /* fule press */
    INT32 total_distance;         /* vehicle distance */
    INT32 total_fule_use;         /* total fule use */
    INT32 water_temperature;      /* water temperature */
    INT32 oil_press;              /* oil press */
    INT32 speed;                  /* vehicle speed */
    INT32 instan_fule_use;        /* instantaneous fule use */
    INT32 air_press;              /* air press */
    DTC   dtc;                    /* DTC(��Ϲ��ϴ���) */
}RECVED_MSG;

/* ��·��PDU */
typedef struct _PDU{
    UINT8                 p_r_dp;
    UINT8                 pf;
    UINT8                 ps;
    UINT8                 sa;
    UINT8                 data[8];
}PDU;

/* �����can�� */
typedef struct _CAN{
    UINT32        id;
    UINT8         dlc;
    UINT8         data[8];
}CAN;                             /* CAN�� */

#ifdef PP_DEBUG_QUEUE
typedef INT32   DATA_T;
#else
typedef CAN     DATA_T;
#endif

typedef struct _QUEUE{
    DATA_T buf[QUEUE_BUF_SIZE];
    INT32 size;
    INT32 head;
    INT32 tail;
    pthread_mutex_t mutex;
}QUEUE;

#endif /* _TYPEDEF_H_ */
