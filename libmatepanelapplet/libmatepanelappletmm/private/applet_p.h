// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _LIBPANELAPPLETMM_APPLET_P_H
#define _LIBPANELAPPLETMM_APPLET_P_H


#include <glibmm/class.h>

namespace Mate
{

namespace Panel
{

class Applet_Class : public Glib::Class
{
public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Applet CppObjectType;
  typedef MatePanelApplet BaseObjectType;
  typedef MatePanelAppletClass BaseClassType;
  typedef Gtk::EventBox_Class CppClassParent;
  typedef GtkEventBoxClass BaseClassParent;

  friend class Applet;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  const Glib::Class& init();

  static void class_init_function(void* g_class, void* class_data);

  static Glib::ObjectBase* wrap_new(GObject*);

protected:

#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  //Callbacks (default signal handlers):
  //These will call the *_impl member methods, which will then call the existing default signal callbacks, if any.
  //You could prevent the original default signal handlers being called by overriding the *_impl method.
  static void change_orient_callback(MatePanelApplet* self, MatePanelAppletOrient p0);
  static void change_size_callback(MatePanelApplet* self, guint p0);
  static void change_background_callback(MatePanelApplet* self, MatePanelAppletBackgroundType p0, GdkColor* p1, GdkPixmap* p2);
  static void move_focus_out_of_applet_callback(MatePanelApplet* self, GtkDirectionType p0);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED

  //Callbacks (virtual functions):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED
};


} // namespace Panel

} // namespace Mate


#endif /* _LIBPANELAPPLETMM_APPLET_P_H */