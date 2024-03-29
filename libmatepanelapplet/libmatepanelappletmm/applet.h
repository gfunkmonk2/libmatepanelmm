// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _LIBPANELAPPLETMM_APPLET_H
#define _LIBPANELAPPLETMM_APPLET_H


#include <glibmm.h>

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


#include <mate-panel-applet.h>
#include <mate-panel-applet-mateconf.h>

#include <libmatepanelappletmm/enums.h>
#include <gtkmm/eventbox.h>

#include <glibmm.h>

#include <gdkmm/color.h>
#include <gdkmm/pixmap.h>

#include <mateconfmm/value.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _MatePanelApplet MatePanelApplet;
typedef struct _MatePanelAppletClass MatePanelAppletClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Mate
{

namespace Panel
{ class Applet_Class; } // namespace Panel

} // namespace Mate
namespace Mate
{

namespace Panel
{


class Applet : public Gtk::EventBox
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef Applet CppObjectType;
  typedef Applet_Class CppClassType;
  typedef MatePanelApplet BaseObjectType;
  typedef MatePanelAppletClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  virtual ~Applet();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class Applet_Class;
  static CppClassType applet_class_;

  // noncopyable
  Applet(const Applet&);
  Applet& operator=(const Applet&);

protected:
  explicit Applet(const Glib::ConstructParams& construct_params);
  explicit Applet(MatePanelApplet* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GtkObject.
  MatePanelApplet*       gobj()       { return reinterpret_cast<MatePanelApplet*>(gobject_); }

  ///Provides access to the underlying C GtkObject.
  const MatePanelApplet* gobj() const { return reinterpret_cast<MatePanelApplet*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

protected:
  //GTK+ Virtual Functions (override these to change behaviour):
#ifdef GLIBMM_VFUNCS_ENABLED
#endif //GLIBMM_VFUNCS_ENABLED

  //Default Signal Handlers::
#ifdef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  virtual void on_change_orientation(AppletOrient orient);
  virtual void on_change_size(int size);
  virtual void on_change_background(AppletBackgroundType type, const Gdk::Color & color, const Glib::RefPtr<const Gdk::Pixmap>& pixmap);
  virtual void on_move_focus_out_of_applet(Gtk::DirectionType direction);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED


private:

  
public:
 

  Applet();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%change_orientation(AppletOrient orient)</tt>
   */

  Glib::SignalProxy1< void,AppletOrient > signal_change_orientation();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%change_size(int size)</tt>
   */

  Glib::SignalProxy1< void,int > signal_change_size();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%change_background(AppletBackgroundType type, const Gdk::Color & color, const Glib::RefPtr<const Gdk::Pixmap>& pixmap)</tt>
   */

  Glib::SignalProxy3< void,AppletBackgroundType,const Gdk::Color &,const Glib::RefPtr<const Gdk::Pixmap>& > signal_change_background();

  
  /**
   * @par Prototype:
   * <tt>void on_my_%move_focus_out_of_applet(Gtk::DirectionType direction)</tt>
   */

  Glib::SignalProxy1< void,Gtk::DirectionType > signal_move_focus_out_of_applet();


  AppletOrient get_orientation() const;
  
  int get_size() const;
  
  bool get_locked_down() const;
 
  
  void request_focus(guint32 timestamp);

  //color and pixmap are output variables. TODO: Document this method properly, as if it had been wrapped automaticaly
  AppletBackgroundType get_background(Gdk::Color& color, Glib::RefPtr<Gdk::Pixmap>& pixmap) const;
  

  void set_background_widget(Gtk::Widget& widget);

  
  Glib::ustring get_preferences_key() const;
  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  void add_preferences(const Glib::ustring& schema_dir);
#else
  void add_preferences(const Glib::ustring& schema_dir, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
  AppletFlags get_flags() const;
  
  void set_flags(AppletFlags flags);

  void set_size_hints(const Glib::ArrayHandle<int>& size_hints, int base_size);

  
  MateComponentControl* get_control();
  
  const MateComponentControl* get_control() const;
  
  MateComponentUIComponent* get_popup_component();
  
  const MateComponentUIComponent* get_popup_component() const;
  
  void setup_menu(const Glib::ArrayHandle<Glib::ustring>& xml, const MateComponentUIVerb* verb_list, gpointer user_data);
  
  void setup_menu(const Glib::ustring& xml, const MateComponentUIVerb* verb_list, gpointer user_data);
  
  void setup_menu(const Glib::ustring& opt_datadir, const Glib::ustring& file, const Glib::ustring& opt_app_name, const MateComponentUIVerb* verb_list, gpointer user_data);
  
  
  Glib::ustring mateconf_get_full_key(const Glib::ustring& key) const;
  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  void mateconf_set(const Glib::ustring& key, bool the_bool);
#else
  void mateconf_set(const Glib::ustring& key, bool the_bool, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  void mateconf_set(const Glib::ustring& key, int the_int);
#else
  void mateconf_set(const Glib::ustring& key, int the_int, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  void mateconf_set(const Glib::ustring& key, const Glib::ustring& the_string);
#else
  void mateconf_set(const Glib::ustring& key, const Glib::ustring& the_string, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  void mateconf_set(const Glib::ustring& key, double the_float);
#else
  void mateconf_set(const Glib::ustring& key, double the_float, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  void mateconf_set(const Glib::ustring& key, const Mate::Conf::Value& value);
#else
  void mateconf_set(const Glib::ustring& key, const Mate::Conf::Value& value, std::auto_ptr<Glib::Error>& error);
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  bool mateconf_get_bool(const Glib::ustring& key) const;
#else
  bool mateconf_get_bool(const Glib::ustring& key, std::auto_ptr<Glib::Error>& error) const;
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  int mateconf_get_int(const Glib::ustring& key) const;
#else
  int mateconf_get_int(const Glib::ustring& key, std::auto_ptr<Glib::Error>& error) const;
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  Glib::ustring mateconf_get_string(const Glib::ustring& key) const;
#else
  Glib::ustring mateconf_get_string(const Glib::ustring& key, std::auto_ptr<Glib::Error>& error) const;
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  double mateconf_get_float(const Glib::ustring& key) const;
#else
  double mateconf_get_float(const Glib::ustring& key, std::auto_ptr<Glib::Error>& error) const;
#endif //GLIBMM_EXCEPTIONS_ENABLED

  
#ifdef GLIBMM_EXCEPTIONS_ENABLED
  Mate::Conf::Value mateconf_get_value(const Glib::ustring& key) const;
#else
  Mate::Conf::Value mateconf_get_value(const Glib::ustring& key, std::auto_ptr<Glib::Error>& error) const;
#endif //GLIBMM_EXCEPTIONS_ENABLED


  //TODO: there has to be a way to do a template function for this, right? -Bryan
  //Maybe - look in mateconfmm for similar stuff, or even reimplement it if these are convenience functions. murrayc.
  void mateconf_set_list(const Glib::ustring& key, const Mate::Conf::SListHandle_ValueBool& list);
  void mateconf_set_list(const Glib::ustring& key, const Mate::Conf::SListHandle_ValueInt& list);
  void mateconf_set_list(const Glib::ustring& key, const Mate::Conf::SListHandle_ValueString& list);
  void mateconf_set_list(const Glib::ustring& key, const Mate::Conf::SListHandle_ValueFloat& list);

  Mate::Conf::SListHandle_ValueBool   mateconf_get_bool_list(const Glib::ustring& key) const;
  Mate::Conf::SListHandle_ValueInt    mateconf_get_int_list(const Glib::ustring& key) const;
  Mate::Conf::SListHandle_ValueString mateconf_get_string_list(const Glib::ustring& key) const;
  Mate::Conf::SListHandle_ValueFloat  mateconf_get_float_list(const Glib::ustring& key) const;

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::ustring> property_name() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::ustring> property_name() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_width_request() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_width_request() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_height_request() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_height_request() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_visible() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_visible() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_sensitive() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_sensitive() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_app_paintable() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_app_paintable() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_can_focus() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_can_focus() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_has_focus() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_has_focus() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_is_focus() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_is_focus() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_can_default() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_can_default() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_has_default() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_has_default() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_receives_default() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_receives_default() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_composite_child() const;
#endif //#GLIBMM_PROPERTIES_ENABLED


  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_no_show_all() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_no_show_all() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<int> property_border_width() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<int> property_border_width() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_visible_window() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_visible_window() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<bool> property_above_child() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<bool> property_above_child() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Gtk::Style> property_style() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Gtk::Style> property_style() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy<Glib::Object> property_parent() ;
#endif //#GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly<Glib::Object> property_parent() const;
#endif //#GLIBMM_PROPERTIES_ENABLED

  #ifdef GLIBMM_PROPERTIES_ENABLED
/** 
   *
   * You rarely need to use properties because there are get_ and set_ methods for almost all of them.
   * @return A PropertyProxy that allows you to get or set the property of the value, or receive notification when
   * the value of the property changes.
   */
  Glib::PropertyProxy_WriteOnly<Glib::Object> property_child() ;
#endif //#GLIBMM_PROPERTIES_ENABLED


};

} // namespace Panel
} // namespace Mate


namespace Glib
{
  /** A Glib::wrap() method for this object.
   * 
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Mate::Panel::Applet
   */
  Mate::Panel::Applet* wrap(MatePanelApplet* object, bool take_copy = false);
} //namespace Glib


#endif /* _LIBPANELAPPLETMM_APPLET_H */
