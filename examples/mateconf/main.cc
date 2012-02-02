/* main.cc
 *
 * Copyright (C) 2003 libmatepanelappletmm Development Team
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */


#include <libmatepanelappletmm.h>
#include <gtkmm.h>
#include <libmatecomponent.h>
#include <iostream>
#include <sstream>

class MyApplet : public Mate::Panel::Applet
{
public:
  explicit MyApplet(MatePanelApplet* castitem);
  virtual ~MyApplet();
  
  static void mateconf_key_diag(MateComponentUIComponent *, void *applet, const gchar *);
};


MyApplet::MyApplet(MatePanelApplet* castitem)
: Mate::Panel::Applet(castitem)
{
  static const Glib::ustring menu_xml = 
    "<popup name=\"button3\">\n"
    "   <menuitem name=\"Get GKey Item\"\n"
    "             verb=\"SimpleGetGKey\" _label=\"Get _MateConf Key...\"\n"
    "             pixtype=\"stock\" pixname=\"gtk-properties\"/>\n"
    "</popup>\n";

  static const MateComponentUIVerb menu_verbs[] = {
    MATECOMPONENT_UI_VERB("SimpleGetGKey", &MyApplet::mateconf_key_diag),
    MATECOMPONENT_UI_VERB_END
  };

  setup_menu(menu_xml, menu_verbs, this);
  add(*Gtk::manage(new Gtk::Label("Simple MateConf Applet")));
  show_all();
}

MyApplet::~MyApplet()
{
}

void MyApplet::mateconf_key_diag(MateComponentUIComponent *, void *applet, const gchar *)
{
  // applet is the c++ wrapped applet, so we have to cast it
  MyApplet *myapplet = static_cast<MyApplet*>(applet);
  std::ostringstream output;

  output.imbue(std::locale(""));
  output << "Applet mateconf key: " << myapplet->mateconf_get_full_key("");
  
  Gtk::MessageDialog dialog(Glib::locale_to_utf8(output.str()));
  dialog.run();
}

int main (int argc, char** argv)
{
  Mate::Panel::init("TestPanelmm", "0.1", argc, argv);

  try
  {
    int returncode = Mate::Panel::factory_main<MyApplet>("OAFIID:SimplePAMateConf_Factory");

    return returncode;
  }
  catch(const Glib::Error& ex)
  {
    std::cout << ex.what() << std::endl;
    return 0;
  }
}
