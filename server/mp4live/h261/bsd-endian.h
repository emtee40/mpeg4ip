/*
 * bsd-endian.h --
 *
 *      FIXME: This file needs a description here.
 *
 * Copyright (c) 1993-2002 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * A. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * B. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * C. Neither the names of the copyright holders nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * @(#) $Header: /cvsroot/mpeg4ip/mpeg4ip/server/mp4live/h261/bsd-endian.h,v 1.1 2003/04/09 00:44:42 wmaycisco Exp $
 */

#include "config.h"

#ifndef BYTE_ORDER
#   define LITTLE_ENDIAN 1234
#   define BIG_ENDIAN 4321
#ifndef WORDS_BIGENDIAN
#       define BYTE_ORDER LITTLE_ENDIAN
#   else
#       define BYTE_ORDER BIG_ENDIAN
#endif
#endif

#if BYTE_ORDER == LITTLE_ENDIAN
#   define SHIFT(n) (24 - (n))
#else
#   define SHIFT(n) (n)
#endif
#define EXTRACT(v, n) (((v) >> SHIFT(n)) & 0xff)
#define SPLICE(v, p, n) (v) |= (p) << SHIFT(n)