/**************************************************************************
 * This file is part of Celera Assembler, a software program that
 * assembles whole-genome shotgun reads into contigs and scaffolds.
 * Copyright (C) 2005, J. Craig Venter Institute. All rights reserved.
 * Author: Brian Walenz
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received (LICENSE.txt) a copy of the GNU General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *************************************************************************/

#ifndef EXCEPTIONUTILS_H
#define EXCEPTIONUTILS_H

static const char* rcsid_EXCEPTIONUTILS_H = "$Id: ExceptionUtils.h,v 1.9 2011-09-05 16:49:45 mkotelbajcvi Exp $";

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <exception>
#include <string>
#include <vector>

using namespace std;

#if defined(__GLIBC__)
#include <execinfo.h>
#endif

#include "AS_global.h"
#include "AS_UTL_alloc.h"
#include "ReflectionUtils.h"
#include "StackTrace.h"
#include "StringUtils.h"

namespace Utility
{
	static const char* DEFAULT_STACK_TRACE_CALLER = "ExceptionUtils";

	class ExceptionUtils
	{
	public:
		static void printStackTrace(FILE* stream = stderr, const string lineDelimiter = DEFAULT_STACK_TRACE_LINE_DELIMITER, 
			const string indent = DEFAULT_STACK_TRACE_INDENT, const string caller = DEFAULT_STACK_TRACE_CALLER, 
			size_t depth = DEFAULT_STACK_TRACE_DEPTH);
		
		static string& getStackTrace(string& buffer, const string lineDelimiter = DEFAULT_STACK_TRACE_LINE_DELIMITER, 
			const string indent = DEFAULT_STACK_TRACE_INDENT, const string caller = DEFAULT_STACK_TRACE_CALLER, 
			size_t depth = DEFAULT_STACK_TRACE_DEPTH);
		
		static StackTrace& getStackTrace(StackTrace& stackTrace, const string caller = DEFAULT_STACK_TRACE_CALLER, 
			size_t depth = DEFAULT_STACK_TRACE_DEPTH);
		
	private:
		ExceptionUtils()
		{
		}
	};
}

#endif
