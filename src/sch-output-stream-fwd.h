/* gEDA - GPL Electronic Design Automation
 * gparts - gEDA Parts Manager
 * Copyright (C) 2010 Edward C. Hennessy
 * Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
 */

/*! \file sch-output-stream-fwd.h
 *
 *  Forward declarations for sch-output-stream.h
 */

#define SCH_TYPE_OUTPUT_STREAM (sch_output_stream_get_type())
#define SCH_OUTPUT_STREAM(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),SCH_TYPE_OUTPUT_STREAM,SchOutputStream))
#define SCH_OUTPUT_STREAM_CLASS(cls) (G_TYPE_CHECK_CLASS_CAST((cls),SCH_TYPE_OUTPUT_STREAM,SchOutputStreamClass))
#define SCH_IS_OUTPUT_STREAM(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),SCH_TYPE_OUTPUT_STREAM))
#define SCH_IS_OUTPUT_STREAM_CLASS(cls) (G_TYPE_CHECK_CLASS_TYPE((cls),SCH_TYPE_OUTPUT_STREAM))
#define SCH_OUTPUT_STREAM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),SCH_TYPE_OUTPUT_STREAM,SchOutputStreamClass))

typedef struct _SchOutputStream SchOutputStream;
typedef struct _SchOutputStreamClass SchOutputStreamClass;

