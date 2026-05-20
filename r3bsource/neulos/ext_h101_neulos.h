/********************************************************
 *
 * Structure for ext_data_fetch_event() filling.
 *
 * Do not edit - automatically generated.
 */

#ifndef __GUARD_H101_NEULOS_EXT_H101_NEULOS_H__
#define __GUARD_H101_NEULOS_EXT_H101_NEULOS_H__

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

typedef struct EXT_STR_h101_NEULOS_t
{
  /* RAW */
  uint32_t tamex_four_TFLCM /* [1,64] */;
  uint32_t tamex_four_TFLCMI[64 EXT_STRUCT_CTRL(tamex_four_TFLCM)] /* [1,64] */;
  uint32_t tamex_four_TFLCME[64 EXT_STRUCT_CTRL(tamex_four_TFLCM)] /* [1,4096] */;
  uint32_t tamex_four_TFLC /* [0,4096] */;
  uint32_t tamex_four_TFLCv[4096 EXT_STRUCT_CTRL(tamex_four_TFLC)] /* [0,65535] */;
  uint32_t tamex_four_TFLFM /* [1,64] */;
  uint32_t tamex_four_TFLFMI[64 EXT_STRUCT_CTRL(tamex_four_TFLFM)] /* [1,64] */;
  uint32_t tamex_four_TFLFME[64 EXT_STRUCT_CTRL(tamex_four_TFLFM)] /* [1,4096] */;
  uint32_t tamex_four_TFLF /* [0,4096] */;
  uint32_t tamex_four_TFLFv[4096 EXT_STRUCT_CTRL(tamex_four_TFLF)] /* [0,65535] */;
  uint32_t tamex_four_TFTCM /* [1,64] */;
  uint32_t tamex_four_TFTCMI[64 EXT_STRUCT_CTRL(tamex_four_TFTCM)] /* [1,64] */;
  uint32_t tamex_four_TFTCME[64 EXT_STRUCT_CTRL(tamex_four_TFTCM)] /* [1,4096] */;
  uint32_t tamex_four_TFTC /* [0,4096] */;
  uint32_t tamex_four_TFTCv[4096 EXT_STRUCT_CTRL(tamex_four_TFTC)] /* [0,65535] */;
  uint32_t tamex_four_TFTFM /* [1,64] */;
  uint32_t tamex_four_TFTFMI[64 EXT_STRUCT_CTRL(tamex_four_TFTFM)] /* [1,64] */;
  uint32_t tamex_four_TFTFME[64 EXT_STRUCT_CTRL(tamex_four_TFTFM)] /* [1,4096] */;
  uint32_t tamex_four_TFTF /* [0,4096] */;
  uint32_t tamex_four_TFTFv[4096 EXT_STRUCT_CTRL(tamex_four_TFTF)] /* [0,65535] */;
  uint32_t tamex_four_TSLCM /* [1,64] */;
  uint32_t tamex_four_TSLCMI[64 EXT_STRUCT_CTRL(tamex_four_TSLCM)] /* [1,64] */;
  uint32_t tamex_four_TSLCME[64 EXT_STRUCT_CTRL(tamex_four_TSLCM)] /* [1,4096] */;
  uint32_t tamex_four_TSLC /* [0,4096] */;
  uint32_t tamex_four_TSLCv[4096 EXT_STRUCT_CTRL(tamex_four_TSLC)] /* [0,65535] */;
  uint32_t tamex_four_TSLFM /* [1,64] */;
  uint32_t tamex_four_TSLFMI[64 EXT_STRUCT_CTRL(tamex_four_TSLFM)] /* [1,64] */;
  uint32_t tamex_four_TSLFME[64 EXT_STRUCT_CTRL(tamex_four_TSLFM)] /* [1,4096] */;
  uint32_t tamex_four_TSLF /* [0,4096] */;
  uint32_t tamex_four_TSLFv[4096 EXT_STRUCT_CTRL(tamex_four_TSLF)] /* [0,65535] */;
  uint32_t tamex_four_TSTCM /* [1,64] */;
  uint32_t tamex_four_TSTCMI[64 EXT_STRUCT_CTRL(tamex_four_TSTCM)] /* [1,64] */;
  uint32_t tamex_four_TSTCME[64 EXT_STRUCT_CTRL(tamex_four_TSTCM)] /* [1,4096] */;
  uint32_t tamex_four_TSTC /* [0,4096] */;
  uint32_t tamex_four_TSTCv[4096 EXT_STRUCT_CTRL(tamex_four_TSTC)] /* [0,65535] */;
  uint32_t tamex_four_TSTFM /* [1,64] */;
  uint32_t tamex_four_TSTFMI[64 EXT_STRUCT_CTRL(tamex_four_TSTFM)] /* [1,64] */;
  uint32_t tamex_four_TSTFME[64 EXT_STRUCT_CTRL(tamex_four_TSTFM)] /* [1,4096] */;
  uint32_t tamex_four_TSTF /* [0,4096] */;
  uint32_t tamex_four_TSTFv[4096 EXT_STRUCT_CTRL(tamex_four_TSTF)] /* [0,65535] */;
  uint32_t tamex_four_TRIGTFLCM /* [1,4] */;
  uint32_t tamex_four_TRIGTFLCMI[4 EXT_STRUCT_CTRL(tamex_four_TRIGTFLCM)] /* [1,4] */;
  uint32_t tamex_four_TRIGTFLCME[4 EXT_STRUCT_CTRL(tamex_four_TRIGTFLCM)] /* [1,256] */;
  uint32_t tamex_four_TRIGTFLC /* [0,256] */;
  uint32_t tamex_four_TRIGTFLCv[256 EXT_STRUCT_CTRL(tamex_four_TRIGTFLC)] /* [0,65535] */;
  uint32_t tamex_four_TRIGTFLFM /* [1,4] */;
  uint32_t tamex_four_TRIGTFLFMI[4 EXT_STRUCT_CTRL(tamex_four_TRIGTFLFM)] /* [1,4] */;
  uint32_t tamex_four_TRIGTFLFME[4 EXT_STRUCT_CTRL(tamex_four_TRIGTFLFM)] /* [1,256] */;
  uint32_t tamex_four_TRIGTFLF /* [0,256] */;
  uint32_t tamex_four_TRIGTFLFv[256 EXT_STRUCT_CTRL(tamex_four_TRIGTFLF)] /* [0,65535] */;

} EXT_STR_h101_NEULOS;

/********************************************************
 *
 * Structure with multiple levels of arrays (partially)
 * recovered (recommended):
 */

typedef struct EXT_STR_h101_NEULOS_onion_t
{
  /* RAW */
  uint32_t tamex_four_TFLCM;
  uint32_t tamex_four_TFLCMI[64 /* tamex_four_TFLCM */];
  uint32_t tamex_four_TFLCME[64 /* tamex_four_TFLCM */];
  uint32_t tamex_four_TFLC;
  uint32_t tamex_four_TFLCv[4096 /* tamex_four_TFLC */];
  uint32_t tamex_four_TFLFM;
  uint32_t tamex_four_TFLFMI[64 /* tamex_four_TFLFM */];
  uint32_t tamex_four_TFLFME[64 /* tamex_four_TFLFM */];
  uint32_t tamex_four_TFLF;
  uint32_t tamex_four_TFLFv[4096 /* tamex_four_TFLF */];
  uint32_t tamex_four_TFTCM;
  uint32_t tamex_four_TFTCMI[64 /* tamex_four_TFTCM */];
  uint32_t tamex_four_TFTCME[64 /* tamex_four_TFTCM */];
  uint32_t tamex_four_TFTC;
  uint32_t tamex_four_TFTCv[4096 /* tamex_four_TFTC */];
  uint32_t tamex_four_TFTFM;
  uint32_t tamex_four_TFTFMI[64 /* tamex_four_TFTFM */];
  uint32_t tamex_four_TFTFME[64 /* tamex_four_TFTFM */];
  uint32_t tamex_four_TFTF;
  uint32_t tamex_four_TFTFv[4096 /* tamex_four_TFTF */];
  uint32_t tamex_four_TSLCM;
  uint32_t tamex_four_TSLCMI[64 /* tamex_four_TSLCM */];
  uint32_t tamex_four_TSLCME[64 /* tamex_four_TSLCM */];
  uint32_t tamex_four_TSLC;
  uint32_t tamex_four_TSLCv[4096 /* tamex_four_TSLC */];
  uint32_t tamex_four_TSLFM;
  uint32_t tamex_four_TSLFMI[64 /* tamex_four_TSLFM */];
  uint32_t tamex_four_TSLFME[64 /* tamex_four_TSLFM */];
  uint32_t tamex_four_TSLF;
  uint32_t tamex_four_TSLFv[4096 /* tamex_four_TSLF */];
  uint32_t tamex_four_TSTCM;
  uint32_t tamex_four_TSTCMI[64 /* tamex_four_TSTCM */];
  uint32_t tamex_four_TSTCME[64 /* tamex_four_TSTCM */];
  uint32_t tamex_four_TSTC;
  uint32_t tamex_four_TSTCv[4096 /* tamex_four_TSTC */];
  uint32_t tamex_four_TSTFM;
  uint32_t tamex_four_TSTFMI[64 /* tamex_four_TSTFM */];
  uint32_t tamex_four_TSTFME[64 /* tamex_four_TSTFM */];
  uint32_t tamex_four_TSTF;
  uint32_t tamex_four_TSTFv[4096 /* tamex_four_TSTF */];
  uint32_t tamex_four_TRIGTFLCM;
  uint32_t tamex_four_TRIGTFLCMI[4 /* tamex_four_TRIGTFLCM */];
  uint32_t tamex_four_TRIGTFLCME[4 /* tamex_four_TRIGTFLCM */];
  uint32_t tamex_four_TRIGTFLC;
  uint32_t tamex_four_TRIGTFLCv[256 /* tamex_four_TRIGTFLC */];
  uint32_t tamex_four_TRIGTFLFM;
  uint32_t tamex_four_TRIGTFLFMI[4 /* tamex_four_TRIGTFLFM */];
  uint32_t tamex_four_TRIGTFLFME[4 /* tamex_four_TRIGTFLFM */];
  uint32_t tamex_four_TRIGTFLF;
  uint32_t tamex_four_TRIGTFLFv[256 /* tamex_four_TRIGTFLF */];

} EXT_STR_h101_NEULOS_onion;

/*******************************************************/

#define EXT_STR_h101_NEULOS_ITEMS_INFO(ok,si,offset,struct_t,printerr) do { \
  ok = 1; \
  /* RAW */ \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLCM,                UINT32,\
                    "tamex_four_TFLCM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLCMI,               UINT32,\
                    "tamex_four_TFLCMI",               "tamex_four_TFLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLCME,               UINT32,\
                    "tamex_four_TFLCME",               "tamex_four_TFLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLC,                 UINT32,\
                    "tamex_four_TFLC",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLCv,                UINT32,\
                    "tamex_four_TFLCv",                "tamex_four_TFLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLFM,                UINT32,\
                    "tamex_four_TFLFM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLFMI,               UINT32,\
                    "tamex_four_TFLFMI",               "tamex_four_TFLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLFME,               UINT32,\
                    "tamex_four_TFLFME",               "tamex_four_TFLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLF,                 UINT32,\
                    "tamex_four_TFLF",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFLFv,                UINT32,\
                    "tamex_four_TFLFv",                "tamex_four_TFLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTCM,                UINT32,\
                    "tamex_four_TFTCM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTCMI,               UINT32,\
                    "tamex_four_TFTCMI",               "tamex_four_TFTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTCME,               UINT32,\
                    "tamex_four_TFTCME",               "tamex_four_TFTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTC,                 UINT32,\
                    "tamex_four_TFTC",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTCv,                UINT32,\
                    "tamex_four_TFTCv",                "tamex_four_TFTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTFM,                UINT32,\
                    "tamex_four_TFTFM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTFMI,               UINT32,\
                    "tamex_four_TFTFMI",               "tamex_four_TFTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTFME,               UINT32,\
                    "tamex_four_TFTFME",               "tamex_four_TFTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTF,                 UINT32,\
                    "tamex_four_TFTF",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TFTFv,                UINT32,\
                    "tamex_four_TFTFv",                "tamex_four_TFTF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLCM,                UINT32,\
                    "tamex_four_TSLCM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLCMI,               UINT32,\
                    "tamex_four_TSLCMI",               "tamex_four_TSLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLCME,               UINT32,\
                    "tamex_four_TSLCME",               "tamex_four_TSLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLC,                 UINT32,\
                    "tamex_four_TSLC",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLCv,                UINT32,\
                    "tamex_four_TSLCv",                "tamex_four_TSLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLFM,                UINT32,\
                    "tamex_four_TSLFM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLFMI,               UINT32,\
                    "tamex_four_TSLFMI",               "tamex_four_TSLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLFME,               UINT32,\
                    "tamex_four_TSLFME",               "tamex_four_TSLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLF,                 UINT32,\
                    "tamex_four_TSLF",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSLFv,                UINT32,\
                    "tamex_four_TSLFv",                "tamex_four_TSLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTCM,                UINT32,\
                    "tamex_four_TSTCM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTCMI,               UINT32,\
                    "tamex_four_TSTCMI",               "tamex_four_TSTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTCME,               UINT32,\
                    "tamex_four_TSTCME",               "tamex_four_TSTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTC,                 UINT32,\
                    "tamex_four_TSTC",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTCv,                UINT32,\
                    "tamex_four_TSTCv",                "tamex_four_TSTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTFM,                UINT32,\
                    "tamex_four_TSTFM",64,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTFMI,               UINT32,\
                    "tamex_four_TSTFMI",               "tamex_four_TSTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTFME,               UINT32,\
                    "tamex_four_TSTFME",               "tamex_four_TSTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTF,                 UINT32,\
                    "tamex_four_TSTF",4096,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TSTFv,                UINT32,\
                    "tamex_four_TSTFv",                "tamex_four_TSTF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLCM,            UINT32,\
                    "tamex_four_TRIGTFLCM",4,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLCMI,           UINT32,\
                    "tamex_four_TRIGTFLCMI",           "tamex_four_TRIGTFLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLCME,           UINT32,\
                    "tamex_four_TRIGTFLCME",           "tamex_four_TRIGTFLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLC,             UINT32,\
                    "tamex_four_TRIGTFLC",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLCv,            UINT32,\
                    "tamex_four_TRIGTFLCv",            "tamex_four_TRIGTFLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLFM,            UINT32,\
                    "tamex_four_TRIGTFLFM",4,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLFMI,           UINT32,\
                    "tamex_four_TRIGTFLFMI",           "tamex_four_TRIGTFLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLFME,           UINT32,\
                    "tamex_four_TRIGTFLFME",           "tamex_four_TRIGTFLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLF,             UINT32,\
                    "tamex_four_TRIGTFLF",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     tamex_four_TRIGTFLFv,            UINT32,\
                    "tamex_four_TRIGTFLFv",            "tamex_four_TRIGTFLF",0/*flags*/); \
  \
} while (0);

#endif/*__GUARD_H101_NEULOS_EXT_H101_NEULOS_H__*/

/*******************************************************/
