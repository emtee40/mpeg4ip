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
 *              Bill May        wmay@cisco.com
 */

#ifndef __OUR_CONFIG_FILE_H__
#define __OUR_CONFIG_FILE_H__ 1

#include <config_file/config_file.h>
enum {
  CONFIG_USE_MPEG4_ISO_ONLY,
  CONFIG_PREV_FILE_0,
  CONFIG_PREV_FILE_1,
  CONFIG_PREV_FILE_2,
  CONFIG_PREV_FILE_3,
  CONFIG_RTP_BUFFER_TIME,
  CONFIG_LOOPED,
  CONFIG_VOLUME,
  CONFIG_MUTED,
  CONFIG_MAX,
};

extern CConfig config;

#endif