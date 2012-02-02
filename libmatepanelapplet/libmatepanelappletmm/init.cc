// -*- c++ -*-
/* $Id$ */

/* init.cc
 *
 * Copyright 2001      Free Software Foundation
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
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmatepanelappletmm/init.h>
#include <libmatepanelappletmm/wrap_init.h>
#include <gtkmm/main.h>
#include <libmatepanelappletmmconfig.h> //For LIBPANELAPPLETMM_VERSION

#include <matecomponent/matecomponent-main.h>

namespace Mate
{

namespace Panel
{

void init(const Glib::ustring& app_id, const Glib::ustring& app_version, int argc, char** argv)
{
  Gtk::Main::init_gtkmm_internals(); //Sets up the g type system and the Glib::wrap() table.
  wrap_init(); //Tells the Glib::wrap() table about the libmatepanelappletmm classes.
  matecomponent_init(&argc, argv);
}

} //namespace Panel
} //namespace Mate
