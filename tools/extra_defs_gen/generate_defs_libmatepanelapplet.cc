/* $Id$ */

/* generate_defs_matevfs.h
 *
 * Copyright (C) 2001 The Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "glibmm_generate_extra_defs/generate_extra_defs.h"
#include <mate-panel-applet.h>
#include <mate-panel-applet-mateconf.h>
#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    std::cout  <<  get_defs(PANEL_TYPE_APPLET);
    return 0;
}
