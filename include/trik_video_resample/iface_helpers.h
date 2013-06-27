#ifndef TRIK_VIDEO_RESAMPLE_INTERNAL_IFACE_HELPERS_H_
#define TRIK_VIDEO_RESAMPLE_INTERNAL_IFACE_HELPERS_H_

#include <xdc/std.h>
#include <ti/xdais/xdas.h>

#include <stdbool.h>

#include "include/trik_video_resample/iface.h"
#include "trik_vidtranscode_resample.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


const TRIK_VIDTRANSCODE_RESAMPLE_Params*	getDefaultParams(void);
const TRIK_VIDTRANSCODE_RESAMPLE_DynamicParams*	getDefaultDynamicParams(void);

void handleBuildDynamicParams(TrikVideoResampleHandle* _handle);
bool handleVerifyParams(const TrikVideoResampleHandle* _handle);

bool reportVersion(XDAS_Int8* _iBuffer, XDAS_Int32 _iBufferSize);

bool handlePickOutputParams(const TrikVideoResampleHandle*	_handle,
                            XDAS_Int32				_iStreamIndex,
                            XDAS_Int32*				_iFormat,
                            XDAS_Int32*				_iHeight,
                            XDAS_Int32*				_iWidth,
                            XDAS_Int32*				_iLineLength);

bool handlePickInputParams(const TrikVideoResampleHandle*	_handle,
                           XDAS_Int32*				_iFormat,
                           XDAS_Int32*				_iHeight,
                           XDAS_Int32*				_iWidth,
                           XDAS_Int32*				_iLineLength);


typedef enum TrikVideoResampleStatus
{
  TRIK_VIDEO_RESAMPLE_STATUS_OK = 0,
  TRIK_VIDEO_RESAMPLE_STATUS_INVALID_ARGUMENTS,
  TRIK_VIDEO_RESAMPLE_STATUS_UNKNOWN_IN_FORMAT,
  TRIK_VIDEO_RESAMPLE_STATUS_UNKNOWN_OUT_FORMAT,
  TRIK_VIDEO_RESAMPLE_STATUS_UNSUPPORTED_FORMATS,
  TRIK_VIDEO_RESAMPLE_STATUS_FAILED,
  TRIK_VIDEO_RESAMPLE_STATUS_OTHER

} TrikVideoResampleStatus;


TrikVideoResampleStatus resampleBuffer(const XDAS_Int8* restrict	_iInBuf,
                                       XDAS_Int32			_iInBufSize,
                                       XDAS_Int32			_iInFormat,
                                       XDAS_Int32			_iInHeight,
                                       XDAS_Int32			_iInWidth,
                                       XDAS_Int32			_iInLineLength,
                                       XDAS_Int8* restrict		_iOutBuf,
                                       XDAS_Int32			_iOutBufSize,
                                       XDAS_Int32*			_iOutBufUsed,
                                       XDAS_Int32			_iOutFormat,
                                       XDAS_Int32			_iOutHeight,
                                       XDAS_Int32			_iOutWidth,
                                       XDAS_Int32			_iOutLineLength);


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif // !TRIK_VIDEO_RESAMPLE_INTERNAL_IFACE_HELPERS_H_
