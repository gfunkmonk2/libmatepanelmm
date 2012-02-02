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
  
  void on_size_change(int size);
  void on_back_change(Mate::Panel::AppletBackgroundType type, const Gdk::Color & color, const Glib::RefPtr<const Gdk::Pixmap>& pixmap);

  static void size_diag(MateComponentUIComponent *, void *applet, const gchar *);
  static void back_diag(MateComponentUIComponent *, void *applet, const gchar *);
};


MyApplet::MyApplet(MatePanelApplet* castitem)
: Mate::Panel::Applet(castitem)
{
  static const Glib::ustring menu_xml = 
    "<popup name=\"button3\">\n"
    "   <menuitem name=\"Get Size Item\"\n"
    "             verb=\"SimpleGetSize\" _label=\"Get _Size...\"\n"
    "             pixtype=\"stock\" pixname=\"gtk-properties\"/>\n"
    "   <menuitem name=\"Get Background Item\"\n"
    "             verb=\"SimpleGetBack\" _label=\"Get _Background...\"\n"
    "             pixtype=\"stock\" pixname=\"gtk-properties\"/>\n"
    "</popup>\n";

  static const MateComponentUIVerb menu_verbs[] = {
    MATECOMPONENT_UI_VERB("SimpleGetSize", &MyApplet::size_diag),
    MATECOMPONENT_UI_VERB("SimpleGetBack", &MyApplet::back_diag),
    MATECOMPONENT_UI_VERB_END
  };

  setup_menu(menu_xml, menu_verbs, this);
  add(*Gtk::manage(new Gtk::Label("Simple Applet")));
  signal_change_size().connect(sigc::mem_fun(*this, &MyApplet::on_size_change));
  signal_change_background().connect(sigc::mem_fun(*this, &MyApplet::on_back_change));

  set_flags( Mate::Panel::APPLET_EXPAND_MINOR );
  
  show_all();
}

MyApplet::~MyApplet()
{
}

void MyApplet::on_size_change(int size)
{
  Gtk::MessageDialog dialog("Changed size!");
  dialog.run();
}

void MyApplet::on_back_change(Mate::Panel::AppletBackgroundType type, const Gdk::Color & color, const Glib::RefPtr<const Gdk::Pixmap>& pixmap)
{
  Gtk::MessageDialog dialog("Changed background!");
  dialog.run();
}

void MyApplet::size_diag(MateComponentUIComponent *, void *applet, const gchar *)
{
  // applet is the c++ wrapped applet, so we have to cast it
  MyApplet *myapplet = static_cast<MyApplet*>(applet);
  std::ostringstream output;

  output.imbue(std::locale(""));
  output << "Applet size: " << myapplet->get_size();
  
  Gtk::MessageDialog dialog(Glib::locale_to_utf8(output.str()));
  dialog.run();
}

void MyApplet::back_diag(MateComponentUIComponent *, void *applet, const gchar *)
{
  MyApplet* myapplet = static_cast<MyApplet*>(applet);

  std::ostringstream output;
  output.imbue(std::locale(""));

  Gdk::Color back_color;
  Glib::RefPtr<Gdk::Pixmap> back_pixmap;
  Mate::Panel::AppletBackgroundType back_type = myapplet->get_background(back_color, back_pixmap);

  {
    using namespace Mate::Panel;
    switch(back_type)
    {
      case COLOR_BACKGROUND:
        output << "Panel uses a color.\nRed: " << back_color.get_red() << "\nGreen: " << back_color.get_green() << "\nBlue: " << back_color.get_blue();
        break;
      case PIXMAP_BACKGROUND:
        output << "Panel uses a pixmap background.";
        break;
      case NO_BACKGROUND:
      default:
        output << "Panel uses Gtk+ theme.";
        break;
    }
  }
  
  Gtk::MessageDialog dialog(Glib::locale_to_utf8(output.str()));
  dialog.run();
}

int main(int argc, char** argv)
{
  Mate::Panel::init("TestPanelmm", "0.1", argc, argv);

  try
  {
    int returncode = Mate::Panel::factory_main<MyApplet>("OAFIID:SimplePA_Factory");

    return returncode;
  }
  catch(const Glib::Error& ex)
  {
    std::cout << ex.what() << std::endl;
    return 0;
  }
}
