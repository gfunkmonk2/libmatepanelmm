/* Copyright 2003 libmatepanelappletmm Development Team
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

#include <libmatepanelappletmm/factory.h>

#include <iostream>

namespace Mate
{

namespace Panel
{

int factory_main_closure(const Glib::ustring& iid, GClosure* closure)
{
  return mate_panel_applet_factory_main_closure(iid.c_str(), Applet::get_type(), closure);
}

MateComponent_Unknown shlib_factory_closure(const Glib::ustring& iid, PortableServer_POA poa, void * impl_ptr, GClosure * closure, CORBA_Environment * ev)
{
  return mate_panel_applet_shlib_factory_closure(iid.c_str(), Applet::get_type(), poa, impl_ptr, closure, ev);
}

} // namespace Panel
} // namespace Mate
