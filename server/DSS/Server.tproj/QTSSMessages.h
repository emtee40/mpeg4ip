/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999 Apple Computer, Inc.  All Rights Reserved.
 * The contents of this file constitute Original Code as defined in and are 
 * subject to the Apple Public Source License Version 1.1 (the "License").  
 * You may not use this file except in compliance with the License.  Please 
 * obtain a copy of the License at http://www.apple.com/publicsource and 
 * read it before using this file.
 * 
 * This Original Code and all software distributed under the License are 
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER 
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, 
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, FITNESS 
 * FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the License for 
 * the specific language governing rights and limitations under the 
 * License.
 * 
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
	File:		QTSSMessages.h

	Contains:	This global dictionary provides a central mapping from message
				names to actual text messages, stored in the provided prefs source.
				
				This allows the whole server to be easily localizeable.
	
	
	
*/

#ifndef __QTSSMESSAGES_H__
#define __QTSSMESSAGES_H__

#include "QTSS.h"
#include "QTSSDictionary.h"
#include "PrefsSource.h"

class QTSSMessages : public QTSSDictionary
{
	public:
	
		// INITIALIZE
		//
		// This function sets up the dictionary map. Must be called before instantiating
		// the first RTSPMessages object.
	
		static void Initialize();
	
		QTSSMessages(PrefsSource* inMessages);
		virtual ~QTSSMessages() {}
		

		//Use the standard GetAttribute method in QTSSDictionary to retrieve messages
		
	private:
	
		enum
		{
			kNumMessages = 59
		};
	
		static char*		sMessagesKeyStrings[];
		static char*	 	sMessages[];
};


#endif // __QTSSMESSAGES_H__