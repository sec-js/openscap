/*
 * Copyright 2015 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * Authors:
 *       Jan Černý <jcerny@redhat.com>
 */

#ifndef OSCAP_DEBUG_H_
#define OSCAP_DEBUG_H_

#include "oscap_export.h"

typedef enum {
	DBG_E = 1,
	DBG_W,
	DBG_I,
	DBG_D,
	DBG_UNKNOWN = -1
} oscap_verbosity_levels;

/**
 * Version of the oscap_dprintf function with support for debug level.
 * Uses logic similar to the debug() macro described above.
 * @param level debug level
 * @param file  name of the source file
 * @param fn    name of the function
 * @param line  current line
 * @param delta_indent changes indentation
 * @param fmt   printf-line format string
 * @param ...   __oscap_dlprintf parameters
 */
OSCAP_API void __oscap_dlprintf(int level, const char *file, const char *fn, size_t line, int delta_indent, const char *fmt, ...);

/**
 * Turn on debugging information
 * @param verbosity_level Verbosity level
 * @param filename Name of file used as output file for store debugging
 *                 and other additional information.
 * @return When an error occurred, returns false, otherwise true.
 */
OSCAP_API bool oscap_set_verbose(const char *verbosity_level, const char *filename);

/**
 * Parse verbosity level from a string.
 * @param level_name Verbosity level as a C string.
 * @return Verbosity level number (or -1 on error).
 */
OSCAP_API oscap_verbosity_levels oscap_verbosity_level_from_cstr(const char *level_name);

/**
 * Print an informational message (verbose level INFO) listing the values
 * of all environment variables known by oscap.
 * See the "List of accepted environment variables" section of the OpenSCAP User Manual.
 */
OSCAP_API void oscap_print_env_vars(void);

#if defined(_WIN32)
int setenv(const char *name, const char *value, int overwrite);
#endif

#endif
