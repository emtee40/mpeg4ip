/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is MPEG4IP.
 * 
 * The Initial Developer of the Original Code is Cisco Systems Inc.
 * Portions created by Cisco Systems Inc. are
 * Copyright (C) Cisco Systems Inc. 2000, 2001.  All Rights Reserved.
 * 
 * Contributor(s): 
 *		Dave Mackie		dmackie@cisco.com
 *		Bill May 		wmay@cisco.com
 */

#ifndef __AUDIO_OSS_SOURCE_H__
#define __AUDIO_OSS_SOURCE_H__

#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>

#include "media_source.h"
#include "audio_encoder.h"

class COSSAudioSource : public CMediaSource {
public:
	COSSAudioSource() : CMediaSource() {
		m_capture = false;
		m_audioDevice = -1;
		m_encoder = NULL;
		m_rawFrameBuffer = NULL;
	}
	~COSSAudioSource() {
		delete m_encoder;
		free(m_rawFrameBuffer);
	}

	bool IsDone() {
		return false;	// live capture device is inexhaustible
	}

	Duration GetElapsedDuration();

	float GetProgress() {
		return 0.0;		// live capture device is inexhaustible
	}

protected:
	int ThreadMain(void);

	void DoStartCapture(void);
	void DoStopCapture(void);

	bool Init(void);
	bool InitDevice(void);
	bool InitEncoder(void);

	void ProcessAudio(void);

protected:
	bool				m_capture;
	int					m_audioDevice;
	CAudioEncoder*		m_encoder;
	Timestamp			m_startTimestamp;
	u_int16_t			m_maxPasses;

	u_int16_t			m_rawSamplesPerFrame;
	u_int16_t*			m_rawFrameBuffer;
	u_int32_t			m_rawFrameSize;
	u_int64_t			m_rawForwardedSamples;
	u_int32_t			m_rawForwardedFrames;

	u_int64_t			m_encodedForwardedSamples;
	u_int32_t			m_encodedForwardedFrames;
};

class CAudioCapabilities {
public:
	CAudioCapabilities(char* deviceName) {
		m_deviceName = stralloc(deviceName);
		m_canOpen = false;
		m_numSamplingRates = 0;

		ProbeDevice();
	}

	~CAudioCapabilities() {
		free(m_deviceName);
	}

	inline bool IsValid() {
		return m_canOpen;
	}

public:
	char*		m_deviceName; 
	bool		m_canOpen;

	// N.B. the rest of the fields are only valid 
	// if m_canOpen is true

	char*		m_driverName; 

	u_int16_t	m_numSamplingRates;
	u_int32_t	m_samplingRates[16];

protected:
	bool ProbeDevice(void);
};

#endif /* __AUDIO_OSS_SOURCE_H__ */