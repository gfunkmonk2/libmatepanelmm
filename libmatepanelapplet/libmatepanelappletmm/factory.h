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


#ifndef _LIBPANELAPPLETMM_FACTORY_H
#define _LIBPANELAPPLETMM_FACTORY_H

#include <glibmm.h>
#include <libmatepanelappletmm/applet.h>

namespace Mate
{

namespace Panel
{

typedef sigc::slot<bool, MatePanelApplet*, const Glib::ustring&> SlotFactory;

namespace
{

//SignalProxy_Factory
//This Signal Proxy allows the C++ coder to specify a SigC::Slot instead of a static function
class SignalProxy_Factory
{
public:
  typedef Mate::Panel::SlotFactory SlotType;

  SignalProxy_Factory(const SlotType& slot);
  ~SignalProxy_Factory();
  
  static gboolean c_callback(MatePanelApplet* applet, const gchar* iid, void* data);

  SlotType slot_;
};

SignalProxy_Factory::SignalProxy_Factory(const SlotType& slot) : slot_(slot)
{
}

SignalProxy_Factory::~SignalProxy_Factory()
{}

gboolean SignalProxy_Factory::c_callback(MatePanelApplet* applet, const gchar* iid, void* data)
{
  SignalProxy_Factory *const self = (SignalProxy_Factory*)(data);

  const Glib::ustring sp_iid = Glib::convert_const_gchar_ptr_to_ustring(iid);
  
  // Just pass the MatePanelApplet* because the developer will need to wrap
  // it with their own class that derives from Mate::Panel::Applet.
  return (self->slot_)(applet, sp_iid);
}

template<class DerivedApplet>
bool applet_factory_callback(MatePanelApplet* mate_panel_applet, const Glib::ustring& /* iid */)
{
  //TODO: When will this C++ wrapper be deleted?
  //When the C object is deleted? When is that? murrayc
  DerivedApplet* applet = Gtk::manage(new DerivedApplet(mate_panel_applet));

  applet->show();

  return true;
}

} // anonymous namespace

template<class DerivedApplet>
int factory_main(const Glib::ustring& iid);

template<class DerivedApplet>
MateComponent_Unknown shlib_factory(const Glib::ustring& iid, PortableServer_POA poa, void* impl_ptr, const SlotFactory& slot, CORBA_Environment* ev);

int factory_main_closure(const Glib::ustring& iid, GClosure *closure);

MateComponent_Unknown shlib_factory_closure(const Glib::ustring& iid, PortableServer_POA poa, void* impl_ptr, GClosure* closure, CORBA_Environment* ev);


template<class DerivedApplet>
int factory_main(const Glib::ustring& iid)
{
  SignalProxy_Factory proxy( sigc::ptr_fun(&applet_factory_callback<DerivedApplet>) );

  return mate_panel_applet_factory_main( iid.c_str(), Applet::get_type(), SignalProxy_Factory::c_callback, &proxy);
}

template<class DerivedApplet>
MateComponent_Unknown shlib_factory(const Glib::ustring& iid, PortableServer_POA poa, void* impl_ptr, const SlotFactory& slot, CORBA_Environment* ev)
{
  SignalProxy_Factory proxy( sigc::ptr_fun(&applet_factory_callback<DerivedApplet>) );

  return mate_panel_applet_shlib_factory( iid.c_str(), Applet::get_type(), poa, impl_ptr, SignalProxy_Factory::c_callback, &proxy, ev);
}

} // namespace Panel
} // namespace Mate

#endif /* _LIBPANELAPPLETMM_FACTORY_H */
