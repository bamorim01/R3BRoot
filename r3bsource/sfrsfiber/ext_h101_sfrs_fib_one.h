/********************************************************
 *
 * Structure for ext_data_fetch_event() filling.
 *
 * Do not edit - automatically generated.
 */

#ifndef __GUARD_H101_SFRS_FIB_ONE_EXT_H101_SFRS_FIB_ONE_H__
#define __GUARD_H101_SFRS_FIB_ONE_EXT_H101_SFRS_FIB_ONE_H__

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

typedef struct EXT_STR_h101_SFRS_FIB_ONE_t
{
  /* RAW */
  uint32_t SFRS_FIB_ONE_DOWN_LCM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_LCMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_LCM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_LCME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_LCM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_LC /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_LCv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_LC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_LFM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_LFMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_LFM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_LFME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_LFM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_LF /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_LFv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_LF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_TCM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_TCMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TCM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_TCME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TCM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_TC /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_TCv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_TFM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_TFMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TFM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_DOWN_TFME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TFM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_TF /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_DOWN_TFv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGLCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGLCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLC /* [0,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGLC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGLFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGLFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLF /* [0,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGLF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGTCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGTCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTC /* [0,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGTC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGTFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGTFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTF /* [0,6] */;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_DOWN_TRIGTF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_LCM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_LCMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_LCM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_LCME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_LCM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_UP_LC /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_UP_LCv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_LC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_LFM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_LFMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_LFM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_LFME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_LFM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_UP_LF /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_UP_LFv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_LF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_TCM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_TCMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TCM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_TCME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TCM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_UP_TC /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_UP_TCv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_TFM /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_TFMI[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TFM)] /* [1,768] */;
  uint32_t SFRS_FIB_ONE_UP_TFME[768 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TFM)] /* [1,49152] */;
  uint32_t SFRS_FIB_ONE_UP_TF /* [0,49152] */;
  uint32_t SFRS_FIB_ONE_UP_TFv[49152 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLCM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLCMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGLCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLCME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGLCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLC /* [0,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLCv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGLC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLFM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLFMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGLFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLFME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGLFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLF /* [0,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGLFv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGLF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTCM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTCMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGTCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTCME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGTCM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTC /* [0,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTCv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGTC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTFM /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTFMI[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGTFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTFME[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGTFM)] /* [1,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTF /* [0,6] */;
  uint32_t SFRS_FIB_ONE_UP_TRIGTFv[6 EXT_STRUCT_CTRL(SFRS_FIB_ONE_UP_TRIGTF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LCM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LCMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_LCM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LCME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_LCM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LC /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LCv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_LC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LFM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LFMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_LFM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LFME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_LFM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LF /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_LFv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_LF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TCM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TCMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TCM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TCME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TCM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TC /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TCv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TFM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TFMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TFM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TFME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TFM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TF /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TFv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGLCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGLCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLC /* [0,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGLC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGLFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGLFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLF /* [0,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGLF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGTCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGTCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTC /* [0,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGTC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGTFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGTFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTF /* [0,2] */;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_RIGHT_TRIGTF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_LCM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_LCMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_LCM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_LCME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_LCM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_LC /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_LCv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_LC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_LFM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_LFMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_LFM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_LFME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_LFM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_LF /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_LFv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_LF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_TCM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_TCMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TCM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_TCME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TCM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_TC /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_TCv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_TFM /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_TFMI[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TFM)] /* [1,256] */;
  uint32_t SFRS_FIB_ONE_LEFT_TFME[256 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TFM)] /* [1,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_TF /* [0,16384] */;
  uint32_t SFRS_FIB_ONE_LEFT_TFv[16384 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGLCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGLCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLC /* [0,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGLC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGLFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGLFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLF /* [0,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGLF)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGTCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGTCM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTC /* [0,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGTC)] /* [0,65535] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFM /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFMI[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGTFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFME[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGTFM)] /* [1,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTF /* [0,2] */;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFv[2 EXT_STRUCT_CTRL(SFRS_FIB_ONE_LEFT_TRIGTF)] /* [0,65535] */;

} EXT_STR_h101_SFRS_FIB_ONE;

/********************************************************
 *
 * Structure with multiple levels of arrays (partially)
 * recovered (recommended):
 */

typedef struct EXT_STR_h101_SFRS_FIB_ONE_onion_t
{
  /* RAW */
  uint32_t SFRS_FIB_ONE_DOWN_LCM;
  uint32_t SFRS_FIB_ONE_DOWN_LCMI[768 /* SFRS_FIB_ONE_DOWN_LCM */];
  uint32_t SFRS_FIB_ONE_DOWN_LCME[768 /* SFRS_FIB_ONE_DOWN_LCM */];
  uint32_t SFRS_FIB_ONE_DOWN_LC;
  uint32_t SFRS_FIB_ONE_DOWN_LCv[49152 /* SFRS_FIB_ONE_DOWN_LC */];
  uint32_t SFRS_FIB_ONE_DOWN_LFM;
  uint32_t SFRS_FIB_ONE_DOWN_LFMI[768 /* SFRS_FIB_ONE_DOWN_LFM */];
  uint32_t SFRS_FIB_ONE_DOWN_LFME[768 /* SFRS_FIB_ONE_DOWN_LFM */];
  uint32_t SFRS_FIB_ONE_DOWN_LF;
  uint32_t SFRS_FIB_ONE_DOWN_LFv[49152 /* SFRS_FIB_ONE_DOWN_LF */];
  uint32_t SFRS_FIB_ONE_DOWN_TCM;
  uint32_t SFRS_FIB_ONE_DOWN_TCMI[768 /* SFRS_FIB_ONE_DOWN_TCM */];
  uint32_t SFRS_FIB_ONE_DOWN_TCME[768 /* SFRS_FIB_ONE_DOWN_TCM */];
  uint32_t SFRS_FIB_ONE_DOWN_TC;
  uint32_t SFRS_FIB_ONE_DOWN_TCv[49152 /* SFRS_FIB_ONE_DOWN_TC */];
  uint32_t SFRS_FIB_ONE_DOWN_TFM;
  uint32_t SFRS_FIB_ONE_DOWN_TFMI[768 /* SFRS_FIB_ONE_DOWN_TFM */];
  uint32_t SFRS_FIB_ONE_DOWN_TFME[768 /* SFRS_FIB_ONE_DOWN_TFM */];
  uint32_t SFRS_FIB_ONE_DOWN_TF;
  uint32_t SFRS_FIB_ONE_DOWN_TFv[49152 /* SFRS_FIB_ONE_DOWN_TF */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCM;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCMI[6 /* SFRS_FIB_ONE_DOWN_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCME[6 /* SFRS_FIB_ONE_DOWN_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLC;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLCv[6 /* SFRS_FIB_ONE_DOWN_TRIGLC */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFM;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFMI[6 /* SFRS_FIB_ONE_DOWN_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFME[6 /* SFRS_FIB_ONE_DOWN_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLF;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGLFv[6 /* SFRS_FIB_ONE_DOWN_TRIGLF */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCM;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCMI[6 /* SFRS_FIB_ONE_DOWN_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCME[6 /* SFRS_FIB_ONE_DOWN_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTC;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTCv[6 /* SFRS_FIB_ONE_DOWN_TRIGTC */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFM;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFMI[6 /* SFRS_FIB_ONE_DOWN_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFME[6 /* SFRS_FIB_ONE_DOWN_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTF;
  uint32_t SFRS_FIB_ONE_DOWN_TRIGTFv[6 /* SFRS_FIB_ONE_DOWN_TRIGTF */];
  uint32_t SFRS_FIB_ONE_UP_LCM;
  uint32_t SFRS_FIB_ONE_UP_LCMI[768 /* SFRS_FIB_ONE_UP_LCM */];
  uint32_t SFRS_FIB_ONE_UP_LCME[768 /* SFRS_FIB_ONE_UP_LCM */];
  uint32_t SFRS_FIB_ONE_UP_LC;
  uint32_t SFRS_FIB_ONE_UP_LCv[49152 /* SFRS_FIB_ONE_UP_LC */];
  uint32_t SFRS_FIB_ONE_UP_LFM;
  uint32_t SFRS_FIB_ONE_UP_LFMI[768 /* SFRS_FIB_ONE_UP_LFM */];
  uint32_t SFRS_FIB_ONE_UP_LFME[768 /* SFRS_FIB_ONE_UP_LFM */];
  uint32_t SFRS_FIB_ONE_UP_LF;
  uint32_t SFRS_FIB_ONE_UP_LFv[49152 /* SFRS_FIB_ONE_UP_LF */];
  uint32_t SFRS_FIB_ONE_UP_TCM;
  uint32_t SFRS_FIB_ONE_UP_TCMI[768 /* SFRS_FIB_ONE_UP_TCM */];
  uint32_t SFRS_FIB_ONE_UP_TCME[768 /* SFRS_FIB_ONE_UP_TCM */];
  uint32_t SFRS_FIB_ONE_UP_TC;
  uint32_t SFRS_FIB_ONE_UP_TCv[49152 /* SFRS_FIB_ONE_UP_TC */];
  uint32_t SFRS_FIB_ONE_UP_TFM;
  uint32_t SFRS_FIB_ONE_UP_TFMI[768 /* SFRS_FIB_ONE_UP_TFM */];
  uint32_t SFRS_FIB_ONE_UP_TFME[768 /* SFRS_FIB_ONE_UP_TFM */];
  uint32_t SFRS_FIB_ONE_UP_TF;
  uint32_t SFRS_FIB_ONE_UP_TFv[49152 /* SFRS_FIB_ONE_UP_TF */];
  uint32_t SFRS_FIB_ONE_UP_TRIGLCM;
  uint32_t SFRS_FIB_ONE_UP_TRIGLCMI[6 /* SFRS_FIB_ONE_UP_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGLCME[6 /* SFRS_FIB_ONE_UP_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGLC;
  uint32_t SFRS_FIB_ONE_UP_TRIGLCv[6 /* SFRS_FIB_ONE_UP_TRIGLC */];
  uint32_t SFRS_FIB_ONE_UP_TRIGLFM;
  uint32_t SFRS_FIB_ONE_UP_TRIGLFMI[6 /* SFRS_FIB_ONE_UP_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGLFME[6 /* SFRS_FIB_ONE_UP_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGLF;
  uint32_t SFRS_FIB_ONE_UP_TRIGLFv[6 /* SFRS_FIB_ONE_UP_TRIGLF */];
  uint32_t SFRS_FIB_ONE_UP_TRIGTCM;
  uint32_t SFRS_FIB_ONE_UP_TRIGTCMI[6 /* SFRS_FIB_ONE_UP_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGTCME[6 /* SFRS_FIB_ONE_UP_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGTC;
  uint32_t SFRS_FIB_ONE_UP_TRIGTCv[6 /* SFRS_FIB_ONE_UP_TRIGTC */];
  uint32_t SFRS_FIB_ONE_UP_TRIGTFM;
  uint32_t SFRS_FIB_ONE_UP_TRIGTFMI[6 /* SFRS_FIB_ONE_UP_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGTFME[6 /* SFRS_FIB_ONE_UP_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_UP_TRIGTF;
  uint32_t SFRS_FIB_ONE_UP_TRIGTFv[6 /* SFRS_FIB_ONE_UP_TRIGTF */];
  uint32_t SFRS_FIB_ONE_RIGHT_LCM;
  uint32_t SFRS_FIB_ONE_RIGHT_LCMI[256 /* SFRS_FIB_ONE_RIGHT_LCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_LCME[256 /* SFRS_FIB_ONE_RIGHT_LCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_LC;
  uint32_t SFRS_FIB_ONE_RIGHT_LCv[16384 /* SFRS_FIB_ONE_RIGHT_LC */];
  uint32_t SFRS_FIB_ONE_RIGHT_LFM;
  uint32_t SFRS_FIB_ONE_RIGHT_LFMI[256 /* SFRS_FIB_ONE_RIGHT_LFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_LFME[256 /* SFRS_FIB_ONE_RIGHT_LFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_LF;
  uint32_t SFRS_FIB_ONE_RIGHT_LFv[16384 /* SFRS_FIB_ONE_RIGHT_LF */];
  uint32_t SFRS_FIB_ONE_RIGHT_TCM;
  uint32_t SFRS_FIB_ONE_RIGHT_TCMI[256 /* SFRS_FIB_ONE_RIGHT_TCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TCME[256 /* SFRS_FIB_ONE_RIGHT_TCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TC;
  uint32_t SFRS_FIB_ONE_RIGHT_TCv[16384 /* SFRS_FIB_ONE_RIGHT_TC */];
  uint32_t SFRS_FIB_ONE_RIGHT_TFM;
  uint32_t SFRS_FIB_ONE_RIGHT_TFMI[256 /* SFRS_FIB_ONE_RIGHT_TFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TFME[256 /* SFRS_FIB_ONE_RIGHT_TFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TF;
  uint32_t SFRS_FIB_ONE_RIGHT_TFv[16384 /* SFRS_FIB_ONE_RIGHT_TF */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCM;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCMI[2 /* SFRS_FIB_ONE_RIGHT_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCME[2 /* SFRS_FIB_ONE_RIGHT_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLC;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLCv[2 /* SFRS_FIB_ONE_RIGHT_TRIGLC */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFM;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFMI[2 /* SFRS_FIB_ONE_RIGHT_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFME[2 /* SFRS_FIB_ONE_RIGHT_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLF;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGLFv[2 /* SFRS_FIB_ONE_RIGHT_TRIGLF */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCM;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCMI[2 /* SFRS_FIB_ONE_RIGHT_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCME[2 /* SFRS_FIB_ONE_RIGHT_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTC;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTCv[2 /* SFRS_FIB_ONE_RIGHT_TRIGTC */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFM;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFMI[2 /* SFRS_FIB_ONE_RIGHT_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFME[2 /* SFRS_FIB_ONE_RIGHT_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTF;
  uint32_t SFRS_FIB_ONE_RIGHT_TRIGTFv[2 /* SFRS_FIB_ONE_RIGHT_TRIGTF */];
  uint32_t SFRS_FIB_ONE_LEFT_LCM;
  uint32_t SFRS_FIB_ONE_LEFT_LCMI[256 /* SFRS_FIB_ONE_LEFT_LCM */];
  uint32_t SFRS_FIB_ONE_LEFT_LCME[256 /* SFRS_FIB_ONE_LEFT_LCM */];
  uint32_t SFRS_FIB_ONE_LEFT_LC;
  uint32_t SFRS_FIB_ONE_LEFT_LCv[16384 /* SFRS_FIB_ONE_LEFT_LC */];
  uint32_t SFRS_FIB_ONE_LEFT_LFM;
  uint32_t SFRS_FIB_ONE_LEFT_LFMI[256 /* SFRS_FIB_ONE_LEFT_LFM */];
  uint32_t SFRS_FIB_ONE_LEFT_LFME[256 /* SFRS_FIB_ONE_LEFT_LFM */];
  uint32_t SFRS_FIB_ONE_LEFT_LF;
  uint32_t SFRS_FIB_ONE_LEFT_LFv[16384 /* SFRS_FIB_ONE_LEFT_LF */];
  uint32_t SFRS_FIB_ONE_LEFT_TCM;
  uint32_t SFRS_FIB_ONE_LEFT_TCMI[256 /* SFRS_FIB_ONE_LEFT_TCM */];
  uint32_t SFRS_FIB_ONE_LEFT_TCME[256 /* SFRS_FIB_ONE_LEFT_TCM */];
  uint32_t SFRS_FIB_ONE_LEFT_TC;
  uint32_t SFRS_FIB_ONE_LEFT_TCv[16384 /* SFRS_FIB_ONE_LEFT_TC */];
  uint32_t SFRS_FIB_ONE_LEFT_TFM;
  uint32_t SFRS_FIB_ONE_LEFT_TFMI[256 /* SFRS_FIB_ONE_LEFT_TFM */];
  uint32_t SFRS_FIB_ONE_LEFT_TFME[256 /* SFRS_FIB_ONE_LEFT_TFM */];
  uint32_t SFRS_FIB_ONE_LEFT_TF;
  uint32_t SFRS_FIB_ONE_LEFT_TFv[16384 /* SFRS_FIB_ONE_LEFT_TF */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCM;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCMI[2 /* SFRS_FIB_ONE_LEFT_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCME[2 /* SFRS_FIB_ONE_LEFT_TRIGLCM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLC;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLCv[2 /* SFRS_FIB_ONE_LEFT_TRIGLC */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFM;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFMI[2 /* SFRS_FIB_ONE_LEFT_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFME[2 /* SFRS_FIB_ONE_LEFT_TRIGLFM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLF;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGLFv[2 /* SFRS_FIB_ONE_LEFT_TRIGLF */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCM;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCMI[2 /* SFRS_FIB_ONE_LEFT_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCME[2 /* SFRS_FIB_ONE_LEFT_TRIGTCM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTC;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTCv[2 /* SFRS_FIB_ONE_LEFT_TRIGTC */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFM;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFMI[2 /* SFRS_FIB_ONE_LEFT_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFME[2 /* SFRS_FIB_ONE_LEFT_TRIGTFM */];
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTF;
  uint32_t SFRS_FIB_ONE_LEFT_TRIGTFv[2 /* SFRS_FIB_ONE_LEFT_TRIGTF */];

} EXT_STR_h101_SFRS_FIB_ONE_onion;

/*******************************************************/

#define EXT_STR_h101_SFRS_FIB_ONE_ITEMS_INFO(ok,si,offset,struct_t,printerr) do { \
  ok = 1; \
  /* RAW */ \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LCM,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_LCM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LCMI,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_LCMI",          "SFRS_FIB_ONE_DOWN_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LCME,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_LCME",          "SFRS_FIB_ONE_DOWN_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LC,            UINT32,\
                    "SFRS_FIB_ONE_DOWN_LC",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LCv,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_LCv",           "SFRS_FIB_ONE_DOWN_LC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LFM,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_LFM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LFMI,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_LFMI",          "SFRS_FIB_ONE_DOWN_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LFME,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_LFME",          "SFRS_FIB_ONE_DOWN_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LF,            UINT32,\
                    "SFRS_FIB_ONE_DOWN_LF",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_LFv,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_LFv",           "SFRS_FIB_ONE_DOWN_LF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TCM,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_TCM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TCMI,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_TCMI",          "SFRS_FIB_ONE_DOWN_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TCME,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_TCME",          "SFRS_FIB_ONE_DOWN_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TC,            UINT32,\
                    "SFRS_FIB_ONE_DOWN_TC",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TCv,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_TCv",           "SFRS_FIB_ONE_DOWN_TC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TFM,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_TFM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TFMI,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_TFMI",          "SFRS_FIB_ONE_DOWN_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TFME,          UINT32,\
                    "SFRS_FIB_ONE_DOWN_TFME",          "SFRS_FIB_ONE_DOWN_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TF,            UINT32,\
                    "SFRS_FIB_ONE_DOWN_TF",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TFv,           UINT32,\
                    "SFRS_FIB_ONE_DOWN_TFv",           "SFRS_FIB_ONE_DOWN_TF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLCM,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLCM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLCMI,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLCMI",      "SFRS_FIB_ONE_DOWN_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLCME,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLCME",      "SFRS_FIB_ONE_DOWN_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLC,        UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLC",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLCv,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLCv",       "SFRS_FIB_ONE_DOWN_TRIGLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLFM,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLFM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLFMI,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLFMI",      "SFRS_FIB_ONE_DOWN_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLFME,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLFME",      "SFRS_FIB_ONE_DOWN_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLF,        UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLF",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGLFv,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGLFv",       "SFRS_FIB_ONE_DOWN_TRIGLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTCM,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTCM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTCMI,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTCMI",      "SFRS_FIB_ONE_DOWN_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTCME,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTCME",      "SFRS_FIB_ONE_DOWN_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTC,        UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTC",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTCv,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTCv",       "SFRS_FIB_ONE_DOWN_TRIGTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTFM,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTFM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTFMI,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTFMI",      "SFRS_FIB_ONE_DOWN_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTFME,      UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTFME",      "SFRS_FIB_ONE_DOWN_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTF,        UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTF",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_DOWN_TRIGTFv,       UINT32,\
                    "SFRS_FIB_ONE_DOWN_TRIGTFv",       "SFRS_FIB_ONE_DOWN_TRIGTF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LCM,             UINT32,\
                    "SFRS_FIB_ONE_UP_LCM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LCMI,            UINT32,\
                    "SFRS_FIB_ONE_UP_LCMI",            "SFRS_FIB_ONE_UP_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LCME,            UINT32,\
                    "SFRS_FIB_ONE_UP_LCME",            "SFRS_FIB_ONE_UP_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LC,              UINT32,\
                    "SFRS_FIB_ONE_UP_LC",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LCv,             UINT32,\
                    "SFRS_FIB_ONE_UP_LCv",             "SFRS_FIB_ONE_UP_LC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LFM,             UINT32,\
                    "SFRS_FIB_ONE_UP_LFM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LFMI,            UINT32,\
                    "SFRS_FIB_ONE_UP_LFMI",            "SFRS_FIB_ONE_UP_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LFME,            UINT32,\
                    "SFRS_FIB_ONE_UP_LFME",            "SFRS_FIB_ONE_UP_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LF,              UINT32,\
                    "SFRS_FIB_ONE_UP_LF",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_LFv,             UINT32,\
                    "SFRS_FIB_ONE_UP_LFv",             "SFRS_FIB_ONE_UP_LF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TCM,             UINT32,\
                    "SFRS_FIB_ONE_UP_TCM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TCMI,            UINT32,\
                    "SFRS_FIB_ONE_UP_TCMI",            "SFRS_FIB_ONE_UP_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TCME,            UINT32,\
                    "SFRS_FIB_ONE_UP_TCME",            "SFRS_FIB_ONE_UP_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TC,              UINT32,\
                    "SFRS_FIB_ONE_UP_TC",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TCv,             UINT32,\
                    "SFRS_FIB_ONE_UP_TCv",             "SFRS_FIB_ONE_UP_TC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TFM,             UINT32,\
                    "SFRS_FIB_ONE_UP_TFM",768,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TFMI,            UINT32,\
                    "SFRS_FIB_ONE_UP_TFMI",            "SFRS_FIB_ONE_UP_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TFME,            UINT32,\
                    "SFRS_FIB_ONE_UP_TFME",            "SFRS_FIB_ONE_UP_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TF,              UINT32,\
                    "SFRS_FIB_ONE_UP_TF",49152,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TFv,             UINT32,\
                    "SFRS_FIB_ONE_UP_TFv",             "SFRS_FIB_ONE_UP_TF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLCM,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLCM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLCMI,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLCMI",        "SFRS_FIB_ONE_UP_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLCME,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLCME",        "SFRS_FIB_ONE_UP_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLC,          UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLC",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLCv,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLCv",         "SFRS_FIB_ONE_UP_TRIGLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLFM,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLFM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLFMI,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLFMI",        "SFRS_FIB_ONE_UP_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLFME,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLFME",        "SFRS_FIB_ONE_UP_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLF,          UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLF",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGLFv,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGLFv",         "SFRS_FIB_ONE_UP_TRIGLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTCM,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTCM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTCMI,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTCMI",        "SFRS_FIB_ONE_UP_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTCME,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTCME",        "SFRS_FIB_ONE_UP_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTC,          UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTC",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTCv,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTCv",         "SFRS_FIB_ONE_UP_TRIGTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTFM,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTFM",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTFMI,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTFMI",        "SFRS_FIB_ONE_UP_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTFME,        UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTFME",        "SFRS_FIB_ONE_UP_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTF,          UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTF",6,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_UP_TRIGTFv,         UINT32,\
                    "SFRS_FIB_ONE_UP_TRIGTFv",         "SFRS_FIB_ONE_UP_TRIGTF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LCM,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LCMI,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LCMI",         "SFRS_FIB_ONE_RIGHT_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LCME,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LCME",         "SFRS_FIB_ONE_RIGHT_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LC,           UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LCv,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LCv",          "SFRS_FIB_ONE_RIGHT_LC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LFM,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LFMI,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LFMI",         "SFRS_FIB_ONE_RIGHT_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LFME,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LFME",         "SFRS_FIB_ONE_RIGHT_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LF,           UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_LFv,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_LFv",          "SFRS_FIB_ONE_RIGHT_LF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TCM,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TCMI,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TCMI",         "SFRS_FIB_ONE_RIGHT_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TCME,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TCME",         "SFRS_FIB_ONE_RIGHT_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TC,           UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TCv,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TCv",          "SFRS_FIB_ONE_RIGHT_TC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TFM,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TFMI,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TFMI",         "SFRS_FIB_ONE_RIGHT_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TFME,         UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TFME",         "SFRS_FIB_ONE_RIGHT_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TF,           UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TFv,          UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TFv",          "SFRS_FIB_ONE_RIGHT_TF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLCM,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLCMI,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLCMI",     "SFRS_FIB_ONE_RIGHT_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLCME,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLCME",     "SFRS_FIB_ONE_RIGHT_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLC,       UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLCv,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLCv",      "SFRS_FIB_ONE_RIGHT_TRIGLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLFM,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLFMI,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLFMI",     "SFRS_FIB_ONE_RIGHT_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLFME,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLFME",     "SFRS_FIB_ONE_RIGHT_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLF,       UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGLFv,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGLFv",      "SFRS_FIB_ONE_RIGHT_TRIGLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTCM,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTCMI,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTCMI",     "SFRS_FIB_ONE_RIGHT_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTCME,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTCME",     "SFRS_FIB_ONE_RIGHT_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTC,       UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTCv,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTCv",      "SFRS_FIB_ONE_RIGHT_TRIGTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTFM,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTFMI,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTFMI",     "SFRS_FIB_ONE_RIGHT_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTFME,     UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTFME",     "SFRS_FIB_ONE_RIGHT_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTF,       UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_RIGHT_TRIGTFv,      UINT32,\
                    "SFRS_FIB_ONE_RIGHT_TRIGTFv",      "SFRS_FIB_ONE_RIGHT_TRIGTF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LCM,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_LCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LCMI,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_LCMI",          "SFRS_FIB_ONE_LEFT_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LCME,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_LCME",          "SFRS_FIB_ONE_LEFT_LCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LC,            UINT32,\
                    "SFRS_FIB_ONE_LEFT_LC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LCv,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_LCv",           "SFRS_FIB_ONE_LEFT_LC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LFM,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_LFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LFMI,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_LFMI",          "SFRS_FIB_ONE_LEFT_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LFME,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_LFME",          "SFRS_FIB_ONE_LEFT_LFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LF,            UINT32,\
                    "SFRS_FIB_ONE_LEFT_LF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_LFv,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_LFv",           "SFRS_FIB_ONE_LEFT_LF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TCM,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_TCM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TCMI,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_TCMI",          "SFRS_FIB_ONE_LEFT_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TCME,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_TCME",          "SFRS_FIB_ONE_LEFT_TCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TC,            UINT32,\
                    "SFRS_FIB_ONE_LEFT_TC",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TCv,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_TCv",           "SFRS_FIB_ONE_LEFT_TC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TFM,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_TFM",256,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TFMI,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_TFMI",          "SFRS_FIB_ONE_LEFT_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TFME,          UINT32,\
                    "SFRS_FIB_ONE_LEFT_TFME",          "SFRS_FIB_ONE_LEFT_TFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TF,            UINT32,\
                    "SFRS_FIB_ONE_LEFT_TF",16384,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TFv,           UINT32,\
                    "SFRS_FIB_ONE_LEFT_TFv",           "SFRS_FIB_ONE_LEFT_TF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLCM,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLCMI,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLCMI",      "SFRS_FIB_ONE_LEFT_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLCME,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLCME",      "SFRS_FIB_ONE_LEFT_TRIGLCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLC,        UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLCv,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLCv",       "SFRS_FIB_ONE_LEFT_TRIGLC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLFM,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLFMI,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLFMI",      "SFRS_FIB_ONE_LEFT_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLFME,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLFME",      "SFRS_FIB_ONE_LEFT_TRIGLFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLF,        UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGLFv,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGLFv",       "SFRS_FIB_ONE_LEFT_TRIGLF",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTCM,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTCM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTCMI,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTCMI",      "SFRS_FIB_ONE_LEFT_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTCME,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTCME",      "SFRS_FIB_ONE_LEFT_TRIGTCM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTC,        UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTC",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTCv,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTCv",       "SFRS_FIB_ONE_LEFT_TRIGTC",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTFM,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTFM",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTFMI,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTFMI",      "SFRS_FIB_ONE_LEFT_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTFME,      UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTFME",      "SFRS_FIB_ONE_LEFT_TRIGTFM",0/*flags*/); \
  EXT_STR_ITEM_INFO2_LIM(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTF,        UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTF",2,0/*flags*/); \
  EXT_STR_ITEM_INFO2_ZZP(ok,si,offset,struct_t,printerr,\
                     SFRS_FIB_ONE_LEFT_TRIGTFv,       UINT32,\
                    "SFRS_FIB_ONE_LEFT_TRIGTFv",       "SFRS_FIB_ONE_LEFT_TRIGTF",0/*flags*/); \
  \
} while (0);

#endif/*__GUARD_H101_SFRS_FIB_ONE_EXT_H101_SFRS_FIB_ONE_H__*/

/*******************************************************/
