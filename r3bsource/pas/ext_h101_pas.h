/********************************************************
 *
 * Structure for ext_data_fetch_event() filling.
 *
 * Do not edit - automatically generated.
 */

#ifndef __GUARD_H101_PAS_EXT_H101_PAS_H__
#define __GUARD_H101_PAS_EXT_H101_PAS_H__

#ifndef __CINT__
# include <stdint.h>
#else
/* For CINT (old version trouble with stdint.h): */
# ifndef uint32_t
typedef unsigned int uint32_t;
typedef          int  int32_t;
# endif
#endif
#ifndef EXT_STRUCT_CTRL
# define EXT_STRUCT_CTRL(x)
#endif

/********************************************************
 *
 * Plain structure (layout as ntuple/root file):
 */

typedef struct EXT_STR_h101_PAS_t
{
  /* RAW */
  uint32_t PAS_DOWN_LCM /* [1,256] */;
  uint32_t PAS_DOWN_LCMI[256 EXT_STRUCT_CTRL(PAS_DOWN_LCM)] /* [1,256] */;
  uint32_t PAS_DOWN_LCME[256 EXT_STRUCT_CTRL(PAS_DOWN_LCM)] /* [1,16384] */;
  uint32_t PAS_DOWN_LC /* [0,16384] */;
  uint32_t PAS_DOWN_LCv[16384 EXT_STRUCT_CTRL(PAS_DOWN_LC)] /* [0,65535] */;
  uint32_t PAS_DOWN_LFM /* [1,256] */;
  uint32_t PAS_DOWN_LFMI[256 EXT_STRUCT_CTRL(PAS_DOWN_LFM)] /* [1,256] */;
  uint32_t PAS_DOWN_LFME[256 EXT_STRUCT_CTRL(PAS_DOWN_LFM)] /* [1,16384] */;
  uint32_t PAS_DOWN_LF /* [0,16384] */;
  uint32_t PAS_DOWN_LFv[16384 EXT_STRUCT_CTRL(PAS_DOWN_LF)] /* [0,65535] */;
  uint32_t PAS_DOWN_TCM /* [1,256] */;
  uint32_t PAS_DOWN_TCMI[256 EXT_STRUCT_CTRL(PAS_DOWN_TCM)] /* [1,256] */;
  uint32_t PAS_DOWN_TCME[256 EXT_STRUCT_CTRL(PAS_DOWN_TCM)] /* [1,16384] */;
  uint32_t PAS_DOWN_TC /* [0,16384] */;
  uint32_t PAS_DOWN_TCv[16384 EXT_STRUCT_CTRL(PAS_DOWN_TC)] /* [0,65535] */;
  uint32_t PAS_DOWN_TFM /* [1,256] */;
  uint32_t PAS_DOWN_TFMI[256 EXT_STRUCT_CTRL(PAS_DOWN_TFM)] /* [1,256] */;
  uint32_t PAS_DOWN_TFME[256 EXT_STRUCT_CTRL(PAS_DOWN_TFM)] /* [1,16384] */;
  uint32_t PAS_DOWN_TF /* [0,16384] */;
  uint32_t PAS_DOWN_TFv[16384 EXT_STRUCT_CTRL(PAS_DOWN_TF)] /* [0,65535] */;
  uint32_t PAS_DOWN_TRIGLCM /* [1,2] */;
  uint32_t PAS_DOWN_TRIGLCMI[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGLCM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGLCME[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGLCM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGLC /* [0,2] */;
  uint32_t PAS_DOWN_TRIGLCv[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGLC)] /* [0,65535] */;
  uint32_t PAS_DOWN_TRIGLFM /* [1,2] */;
  uint32_t PAS_DOWN_TRIGLFMI[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGLFM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGLFME[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGLFM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGLF /* [0,2] */;
  uint32_t PAS_DOWN_TRIGLFv[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGLF)] /* [0,65535] */;
  uint32_t PAS_DOWN_TRIGTCM /* [1,2] */;
  uint32_t PAS_DOWN_TRIGTCMI[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGTCM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGTCME[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGTCM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGTC /* [0,2] */;
  uint32_t PAS_DOWN_TRIGTCv[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGTC)] /* [0,65535] */;
  uint32_t PAS_DOWN_TRIGTFM /* [1,2] */;
  uint32_t PAS_DOWN_TRIGTFMI[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGTFM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGTFME[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGTFM)] /* [1,2] */;
  uint32_t PAS_DOWN_TRIGTF /* [0,2] */;
  uint32_t PAS_DOWN_TRIGTFv[2 EXT_STRUCT_CTRL(PAS_DOWN_TRIGTF)] /* [0,65535] */;
  uint32_t PAS_UP_LCM /* [1,256] */;
  uint32_t PAS_UP_LCMI[256 EXT_STRUCT_CTRL(PAS_UP_LCM)] /* [1,256] */;
  uint32_t PAS_UP_LCME[256 EXT_STRUCT_CTRL(PAS_UP_LCM)] /* [1,16384] */;
  uint32_t PAS_UP_LC /* [0,16384] */;
  uint32_t PAS_UP_LCv[16384 EXT_STRUCT_CTRL(PAS_UP_LC)] /* [0,65535] */;
  uint32_t PAS_UP_LFM /* [1,256] */;
  uint32_t PAS_UP_LFMI[256 EXT_STRUCT_CTRL(PAS_UP_LFM)] /* [1,256] */;
  uint32_t PAS_UP_LFME[256 EXT_STRUCT_CTRL(PAS_UP_LFM)] /* [1,16384] */;
  uint32_t PAS_UP_LF /* [0,16384] */;
  uint32_t PAS_UP_LFv[16384 EXT_STRUCT_CTRL(PAS_UP_LF)] /* [0,65535] */;
  uint32_t PAS_UP_TCM /* [1,256] */;
  uint32_t PAS_UP_TCMI[256 EXT_STRUCT_CTRL(PAS_UP_TCM)] /* [1,256] */;
  uint32_t PAS_UP_TCME[256 EXT_STRUCT_CTRL(PAS_UP_TCM)] /* [1,16384] */;
  uint32_t PAS_UP_TC /* [0,16384] */;
  uint32_t PAS_UP_TCv[16384 EXT_STRUCT_CTRL(PAS_UP_TC)] /* [0,65535] */;
  uint32_t PAS_UP_TFM /* [1,256] */;
  uint32_t PAS_UP_TFMI[256 EXT_STRUCT_CTRL(PAS_UP_TFM)] /* [1,256] */;
  uint32_t PAS_UP_TFME[256 EXT_STRUCT_CTRL(PAS_UP_TFM)] /* [1,16384] */;
  uint32_t PAS_UP_TF /* [0,16384] */;
  uint32_t PAS_UP_TFv[16384 EXT_STRUCT_CTRL(PAS_UP_TF)] /* [0,65535] */;
  uint32_t PAS_UP_TRIGLCM /* [1,2] */;
  uint32_t PAS_UP_TRIGLCMI[2 EXT_STRUCT_CTRL(PAS_UP_TRIGLCM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGLCME[2 EXT_STRUCT_CTRL(PAS_UP_TRIGLCM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGLC /* [0,2] */;
  uint32_t PAS_UP_TRIGLCv[2 EXT_STRUCT_CTRL(PAS_UP_TRIGLC)] /* [0,65535] */;
  uint32_t PAS_UP_TRIGLFM /* [1,2] */;
  uint32_t PAS_UP_TRIGLFMI[2 EXT_STRUCT_CTRL(PAS_UP_TRIGLFM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGLFME[2 EXT_STRUCT_CTRL(PAS_UP_TRIGLFM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGLF /* [0,2] */;
  uint32_t PAS_UP_TRIGLFv[2 EXT_STRUCT_CTRL(PAS_UP_TRIGLF)] /* [0,65535] */;
  uint32_t PAS_UP_TRIGTCM /* [1,2] */;
  uint32_t PAS_UP_TRIGTCMI[2 EXT_STRUCT_CTRL(PAS_UP_TRIGTCM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGTCME[2 EXT_STRUCT_CTRL(PAS_UP_TRIGTCM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGTC /* [0,2] */;
  uint32_t PAS_UP_TRIGTCv[2 EXT_STRUCT_CTRL(PAS_UP_TRIGTC)] /* [0,65535] */;
  uint32_t PAS_UP_TRIGTFM /* [1,2] */;
  uint32_t PAS_UP_TRIGTFMI[2 EXT_STRUCT_CTRL(PAS_UP_TRIGTFM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGTFME[2 EXT_STRUCT_CTRL(PAS_UP_TRIGTFM)] /* [1,2] */;
  uint32_t PAS_UP_TRIGTF /* [0,2] */;
  uint32_t PAS_UP_TRIGTFv[2 EXT_STRUCT_CTRL(PAS_UP_TRIGTF)] /* [0,65535] */;

} EXT_STR_h101_PAS;

/********************************************************
 *
 * Structure with multiple levels of arrays (partially)
 * recovered (recommended):
 */

typedef struct EXT_STR_h101_PAS_onion_t
{
  /* RAW */
  uint32_t PAS_DOWN_LCM;
  uint32_t PAS_DOWN_LCMI[256 /* PAS_DOWN_LCM */];
  uint32_t PAS_DOWN_LCME[256 /* PAS_DOWN_LCM */];
  uint32_t PAS_DOWN_LC;
  uint32_t PAS_DOWN_LCv[16384 /* PAS_DOWN_LC */];
  uint32_t PAS_DOWN_LFM;
  uint32_t PAS_DOWN_LFMI[256 /* PAS_DOWN_LFM */];
  uint32_t PAS_DOWN_LFME[256 /* PAS_DOWN_LFM */];
  uint32_t PAS_DOWN_LF;
  uint32_t PAS_DOWN_LFv[16384 /* PAS_DOWN_LF */];
  uint32_t PAS_DOWN_TCM;
  uint32_t PAS_DOWN_TCMI[256 /* PAS_DOWN_TCM */];
  uint32_t PAS_DOWN_TCME[256 /* PAS_DOWN_TCM */];
  uint32_t PAS_DOWN_TC;
  uint32_t PAS_DOWN_TCv[16384 /* PAS_DOWN_TC */];
  uint32_t PAS_DOWN_TFM;
  uint32_t PAS_DOWN_TFMI[256 /* PAS_DOWN_TFM */];
  uint32_t PAS_DOWN_TFME[256 /* PAS_DOWN_TFM */];
  uint32_t PAS_DOWN_TF;
  uint32_t PAS_DOWN_TFv[16384 /* PAS_DOWN_TF */];
  uint32_t PAS_DOWN_TRIGLCM;
  uint32_t PAS_DOWN_TRIGLCMI[2 /* PAS_DOWN_TRIGLCM */];
  uint32_t PAS_DOWN_TRIGLCME[2 /* PAS_DOWN_TRIGLCM */];
  uint32_t PAS_DOWN_TRIGLC;
  uint32_t PAS_DOWN_TRIGLCv[2 /* PAS_DOWN_TRIGLC */];
  uint32_t PAS_DOWN_TRIGLFM;
  uint32_t PAS_DOWN_TRIGLFMI[2 /* PAS_DOWN_TRIGLFM */];
  uint32_t PAS_DOWN_TRIGLFME[2 /* PAS_DOWN_TRIGLFM */];
  uint32_t PAS_DOWN_TRIGLF;
  uint32_t PAS_DOWN_TRIGLFv[2 /* PAS_DOWN_TRIGLF */];
  uint32_t PAS_DOWN_TRIGTCM;
  uint32_t PAS_DOWN_TRIGTCMI[2 /* PAS_DOWN_TRIGTCM */];
  uint32_t PAS_DOWN_TRIGTCME[2 /* PAS_DOWN_TRIGTCM */];
  uint32_t PAS_DOWN_TRIGTC;
  uint32_t PAS_DOWN_TRIGTCv[2 /* PAS_DOWN_TRIGTC */];
  uint32_t PAS_DOWN_TRIGTFM;
  uint32_t PAS_DOWN_TRIGTFMI[2 /* PAS_DOWN_TRIGTFM */];
  uint32_t PAS_DOWN_TRIGTFME[2 /* PAS_DOWN_TRIGTFM */];
  uint32_t PAS_DOWN_TRIGTF;
  uint32_t PAS_DOWN_TRIGTFv[2 /* PAS_DOWN_TRIGTF */];
  uint32_t PAS_UP_LCM;
  uint32_t PAS_UP_LCMI[256 /* PAS_UP_LCM */];
  uint32_t PAS_UP_LCME[256 /* PAS_UP_LCM */];
  uint32_t PAS_UP_LC;
  uint32_t PAS_UP_LCv[16384 /* PAS_UP_LC */];
  uint32_t PAS_UP_LFM;
  uint32_t PAS_UP_LFMI[256 /* PAS_UP_LFM */];
  uint32_t PAS_UP_LFME[256 /* PAS_UP_LFM */];
  uint32_t PAS_UP_LF;
  uint32_t PAS_UP_LFv[16384 /* PAS_UP_LF */];
  uint32_t PAS_UP_TCM;
  uint32_t PAS_UP_TCMI[256 /* PAS_UP_TCM */];
  uint32_t PAS_UP_TCME[256 /* PAS_UP_TCM */];
  uint32_t PAS_UP_TC;
  uint32_t PAS_UP_TCv[16384 /* PAS_UP_TC */];
  uint32_t PAS_UP_TFM;
  uint32_t PAS_UP_TFMI[256 /* PAS_UP_TFM */];
  uint32_t PAS_UP_TFME[256 /* PAS_UP_TFM */];
  uint32_t PAS_UP_TF;
  uint32_t PAS_UP_TFv[16384 /* PAS_UP_TF */];
  uint32_t PAS_UP_TRIGLCM;
  uint32_t PAS_UP_TRIGLCMI[2 /* PAS_UP_TRIGLCM */];
  uint32_t PAS_UP_TRIGLCME[2 /* PAS_UP_TRIGLCM */];
  uint32_t PAS_UP_TRIGLC;
  uint32_t PAS_UP_TRIGLCv[2 /* PAS_UP_TRIGLC */];
  uint32_t PAS_UP_TRIGLFM;
  uint32_t PAS_UP_TRIGLFMI[2 /* PAS_UP_TRIGLFM */];
  uint32_t PAS_UP_TRIGLFME[2 /* PAS_UP_TRIGLFM */];
  uint32_t PAS_UP_TRIGLF;
  uint32_t PAS_UP_TRIGLFv[2 /* PAS_UP_TRIGLF */];
  uint32_t PAS_UP_TRIGTCM;
  uint32_t PAS_UP_TRIGTCMI[2 /* PAS_UP_TRIGTCM */];
  uint32_t PAS_UP_TRIGTCME[2 /* PAS_UP_TRIGTCM */];
  uint32_t PAS_UP_TRIGTC;
  uint32_t PAS_UP_TRIGTCv[2 /* PAS_UP_TRIGTC */];
  uint32_t PAS_UP_TRIGTFM;
  uint32_t PAS_UP_TRIGTFMI[2 /* PAS_UP_TRIGTFM */];
  uint32_t PAS_UP_TRIGTFME[2 /* PAS_UP_TRIGTFM */];
  uint32_t PAS_UP_TRIGTF;
  uint32_t PAS_UP_TRIGTFv[2 /* PAS_UP_TRIGTF */];

} EXT_STR_h101_PAS_onion;

/*******************************************************/

#define EXT_STR_h101_PAS_ITEMS_INFO(ok,si,offset,struct_t,printerr) do { \
  ok = 1; \
  /* RAW */ \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LCM,                    UINT32,\
                    "PAS_DOWN_LCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LCMI,                   UINT32,\
                    "PAS_DOWN_LCMI",                   "PAS_DOWN_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LCME,                   UINT32,\
                    "PAS_DOWN_LCME",                   "PAS_DOWN_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LC,                     UINT32,\
                    "PAS_DOWN_LC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LCv,                    UINT32,\
                    "PAS_DOWN_LCv",                    "PAS_DOWN_LC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LFM,                    UINT32,\
                    "PAS_DOWN_LFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LFMI,                   UINT32,\
                    "PAS_DOWN_LFMI",                   "PAS_DOWN_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LFME,                   UINT32,\
                    "PAS_DOWN_LFME",                   "PAS_DOWN_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LF,                     UINT32,\
                    "PAS_DOWN_LF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_LFv,                    UINT32,\
                    "PAS_DOWN_LFv",                    "PAS_DOWN_LF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TCM,                    UINT32,\
                    "PAS_DOWN_TCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TCMI,                   UINT32,\
                    "PAS_DOWN_TCMI",                   "PAS_DOWN_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TCME,                   UINT32,\
                    "PAS_DOWN_TCME",                   "PAS_DOWN_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TC,                     UINT32,\
                    "PAS_DOWN_TC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TCv,                    UINT32,\
                    "PAS_DOWN_TCv",                    "PAS_DOWN_TC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TFM,                    UINT32,\
                    "PAS_DOWN_TFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TFMI,                   UINT32,\
                    "PAS_DOWN_TFMI",                   "PAS_DOWN_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TFME,                   UINT32,\
                    "PAS_DOWN_TFME",                   "PAS_DOWN_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TF,                     UINT32,\
                    "PAS_DOWN_TF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TFv,                    UINT32,\
                    "PAS_DOWN_TFv",                    "PAS_DOWN_TF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLCM,                UINT32,\
                    "PAS_DOWN_TRIGLCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLCMI,               UINT32,\
                    "PAS_DOWN_TRIGLCMI",               "PAS_DOWN_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLCME,               UINT32,\
                    "PAS_DOWN_TRIGLCME",               "PAS_DOWN_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLC,                 UINT32,\
                    "PAS_DOWN_TRIGLC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLCv,                UINT32,\
                    "PAS_DOWN_TRIGLCv",                "PAS_DOWN_TRIGLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLFM,                UINT32,\
                    "PAS_DOWN_TRIGLFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLFMI,               UINT32,\
                    "PAS_DOWN_TRIGLFMI",               "PAS_DOWN_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLFME,               UINT32,\
                    "PAS_DOWN_TRIGLFME",               "PAS_DOWN_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLF,                 UINT32,\
                    "PAS_DOWN_TRIGLF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGLFv,                UINT32,\
                    "PAS_DOWN_TRIGLFv",                "PAS_DOWN_TRIGLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTCM,                UINT32,\
                    "PAS_DOWN_TRIGTCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTCMI,               UINT32,\
                    "PAS_DOWN_TRIGTCMI",               "PAS_DOWN_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTCME,               UINT32,\
                    "PAS_DOWN_TRIGTCME",               "PAS_DOWN_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTC,                 UINT32,\
                    "PAS_DOWN_TRIGTC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTCv,                UINT32,\
                    "PAS_DOWN_TRIGTCv",                "PAS_DOWN_TRIGTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTFM,                UINT32,\
                    "PAS_DOWN_TRIGTFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTFMI,               UINT32,\
                    "PAS_DOWN_TRIGTFMI",               "PAS_DOWN_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTFME,               UINT32,\
                    "PAS_DOWN_TRIGTFME",               "PAS_DOWN_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTF,                 UINT32,\
                    "PAS_DOWN_TRIGTF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_DOWN_TRIGTFv,                UINT32,\
                    "PAS_DOWN_TRIGTFv",                "PAS_DOWN_TRIGTF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LCM,                      UINT32,\
                    "PAS_UP_LCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LCMI,                     UINT32,\
                    "PAS_UP_LCMI",                     "PAS_UP_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LCME,                     UINT32,\
                    "PAS_UP_LCME",                     "PAS_UP_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LC,                       UINT32,\
                    "PAS_UP_LC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LCv,                      UINT32,\
                    "PAS_UP_LCv",                      "PAS_UP_LC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LFM,                      UINT32,\
                    "PAS_UP_LFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LFMI,                     UINT32,\
                    "PAS_UP_LFMI",                     "PAS_UP_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LFME,                     UINT32,\
                    "PAS_UP_LFME",                     "PAS_UP_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LF,                       UINT32,\
                    "PAS_UP_LF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_LFv,                      UINT32,\
                    "PAS_UP_LFv",                      "PAS_UP_LF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TCM,                      UINT32,\
                    "PAS_UP_TCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TCMI,                     UINT32,\
                    "PAS_UP_TCMI",                     "PAS_UP_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TCME,                     UINT32,\
                    "PAS_UP_TCME",                     "PAS_UP_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TC,                       UINT32,\
                    "PAS_UP_TC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TCv,                      UINT32,\
                    "PAS_UP_TCv",                      "PAS_UP_TC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TFM,                      UINT32,\
                    "PAS_UP_TFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TFMI,                     UINT32,\
                    "PAS_UP_TFMI",                     "PAS_UP_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TFME,                     UINT32,\
                    "PAS_UP_TFME",                     "PAS_UP_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TF,                       UINT32,\
                    "PAS_UP_TF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TFv,                      UINT32,\
                    "PAS_UP_TFv",                      "PAS_UP_TF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLCM,                  UINT32,\
                    "PAS_UP_TRIGLCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLCMI,                 UINT32,\
                    "PAS_UP_TRIGLCMI",                 "PAS_UP_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLCME,                 UINT32,\
                    "PAS_UP_TRIGLCME",                 "PAS_UP_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLC,                   UINT32,\
                    "PAS_UP_TRIGLC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLCv,                  UINT32,\
                    "PAS_UP_TRIGLCv",                  "PAS_UP_TRIGLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLFM,                  UINT32,\
                    "PAS_UP_TRIGLFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLFMI,                 UINT32,\
                    "PAS_UP_TRIGLFMI",                 "PAS_UP_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLFME,                 UINT32,\
                    "PAS_UP_TRIGLFME",                 "PAS_UP_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLF,                   UINT32,\
                    "PAS_UP_TRIGLF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGLFv,                  UINT32,\
                    "PAS_UP_TRIGLFv",                  "PAS_UP_TRIGLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTCM,                  UINT32,\
                    "PAS_UP_TRIGTCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTCMI,                 UINT32,\
                    "PAS_UP_TRIGTCMI",                 "PAS_UP_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTCME,                 UINT32,\
                    "PAS_UP_TRIGTCME",                 "PAS_UP_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTC,                   UINT32,\
                    "PAS_UP_TRIGTC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTCv,                  UINT32,\
                    "PAS_UP_TRIGTCv",                  "PAS_UP_TRIGTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTFM,                  UINT32,\
                    "PAS_UP_TRIGTFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTFMI,                 UINT32,\
                    "PAS_UP_TRIGTFMI",                 "PAS_UP_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTFME,                 UINT32,\
                    "PAS_UP_TRIGTFME",                 "PAS_UP_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTF,                   UINT32,\
                    "PAS_UP_TRIGTF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     PAS_UP_TRIGTFv,                  UINT32,\
                    "PAS_UP_TRIGTFv",                  "PAS_UP_TRIGTF",0/*flags*/); \
  \
} while (0);

#endif/*__GUARD_H101_PAS_EXT_H101_PAS_H__*/

/*******************************************************/
