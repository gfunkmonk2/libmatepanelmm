define(`__GUCHARP_TO_USTRING',`Glib::convert_const_gchar_ptr_to_ustring((const char*)$`'3)')

_CONVERSION(`guchar*',`Glib::ustring',__GUCHARP_TO_USTRING)
_CONVERSION(`const Glib::ustring&',`const guchar*',`($2)$3.c_str()')

_CONVERSION(`const Glib::ArrayHandle<Glib::ustring>&',`const gchar*',`($2)($3.data())')
_CONVERSION(`const gchar*',`const Glib::ArrayHandle<Glib::ustring>&',`Glib::ArrayHandle<Glib::ustring>($2, Glib::OWNERSHIP_SHALLOW)')

_CONVERSION(`const Glib::ArrayHandle<MateComponentUIVerb>&',`const MateComponentUIVerb*',`($2)($3.data())')
_CONVERSION(`const MateComponentUIVerb*',`const Glib::ArrayHandle<MateComponentUIVerb>&',`Glib::ArrayHandle<MateComponentUIVerb>($2, Glib::OWNERSHIP_SHALLOW)')

_CONVERSION(`MateComponentControl*',`const MateComponentControl*',`($3)')
_CONVERSION(`MateComponentUIComponent*',`const MateComponentUIComponent*',`($3)')

# The GSList conversions
define(`__FL2H_DEEP',`$`'2($`'3, Glib::OWNERSHIP_DEEP)')
define(`__FL2H_SHALLOW',`$`'2($`'3, Glib::OWNERSHIP_SHALLOW)')
define(`__FL2H_NONE',`$`'2($`'3, Glib::OWNERSHIP_NONE)')
_CONVERSION(`GSList*',`Glib::SListHandle<Entry>',__FL2H_SHALLOW)
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::ustring>',__FL2H_DEEP)
# These are for MateConfValues, which are optimized to reduce copies
_CONVERSION(`GSList*',`SListHandle_ValueString',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueSchema',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueInt',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueBool',__FL2H_NONE)
_CONVERSION(`GSList*',`SListHandle_ValueFloat',__FL2H_NONE)
_CONVERSION(`const SListHandle_ValueString&',`GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueSchema&',`GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueInt&',   `GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueBool&',  `GSList*',`$3.data()')
_CONVERSION(`const SListHandle_ValueFloat&', `GSList*',`$3.data()')

_CONVERSION(`int',`guint',($2)($3))
_CONVERSION(`guint',`int',($2)($3))

_CONVERSION(`gpointer', `GdkColor*', `($2)($3)')
_CONVERSION(`GdkColor*', `gpointer', `($2)($3)')

_CONVERSION(`Gdk::Color&', `GdkColor*',`($3).gobj()')
_CONVERSION(`const Glib::RefPtr<Gdk::Pixmap>&', `GdkPixmap**', `&(Glib::unwrap($3))')

_CONVERSION(`MateConfValue*',  `Mate::Conf::Value', `Mate::Conf::Value($3)')
_CONVERSION(`Mate::Conf::Value', `MateConfValue*',  `($3).gobj()')

_CONVERSION(`const Mate::Conf::Value&',`MateConfValue*',`const_cast<MateConfValue*>($3.gobj())')
_CONVERSION(`MateConfValue*',`const Mate::Conf::Value&',`Mate::Conf::Value($3)')

#TODO: Patch the C library:
_CONVERSION(`const std::string&',`gchar*',`($2)$3.c_str()')

dnl Enumeration and various typedef conversions:
dnl --------------------------------------------

_CONVERSION(`AppletOrient', `MatePanelAppletOrient', `($2)($3)')
_CONVERSION(`MatePanelAppletOrient', `AppletOrient', `($2)($3)')

_CONVERSION(`AppletBackgroundType', `MatePanelAppletBackgroundType', `($2)($3)')
_CONVERSION(`MatePanelAppletBackgroundType', `AppletBackgroundType', `($2)($3)')

_CONVERSION(`AppletFlags', `MatePanelAppletFlags', `($2)($3)')
_CONVERSION(`MatePanelAppletFlags', `AppletFlags', `($2)($3)')


These are for signals. That's why they use wrap( , true):
_CONVERSION(`const Gdk::Color&',`GdkColor*',`const_cast<GdkColor*>(($3).gobj())')
_CONVERSION(`GdkColor*',`const Gdk::Color&',`Glib::wrap($3, true)')

_CONVERSION(`const Glib::RefPtr<const Gdk::Pixmap>&',`GdkPixmap*',`const_cast<GdkPixmap*>(Glib::unwrap($3))')
_CONVERSION(`GdkPixmap*',`const Glib::RefPtr<const Gdk::Pixmap>&',`Glib::wrap((GdkPixmapObject*)($3), true)')
