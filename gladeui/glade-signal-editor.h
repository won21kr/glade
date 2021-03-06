#ifndef __GLADE_SIGNAL_EDITOR_H__
#define __GLADE_SIGNAL_EDITOR_H__

#include <gladeui/glade.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GLADE_TYPE_SIGNAL_EDITOR            (glade_signal_editor_get_type ())
#define GLADE_SIGNAL_EDITOR(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GLADE_TYPE_SIGNAL_EDITOR, GladeSignalEditor))
#define GLADE_SIGNAL_EDITOR_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GLADE_TYPE_SIGNAL_EDITOR, GladeSignalEditorClass))
#define GLADE_IS_SIGNAL_EDITOR(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GLADE_TYPE_SIGNAL_EDITOR))
#define GLADE_IS_SIGNAL_EDITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GLADE_TYPE_SIGNAL_EDITOR))
#define GLADE_SIGNAL_EDITOR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GLADE_TYPE_SIGNAL_EDITOR, GladeSignalEditorClass))

typedef struct _GladeSignalEditor  GladeSignalEditor;
typedef struct _GladeSignalEditorPrivate  GladeSignalEditorPrivate;
typedef struct _GladeSignalEditorClass  GladeSignalEditorClass;

/* The GladeSignalEditor is used to house the signal editor interface and
 * associated functionality.
 */
struct _GladeSignalEditor
{
  GtkBox parent;

  GladeSignalEditorPrivate *priv;
};

struct _GladeSignalEditorClass
{
  GtkBoxClass parent_class;

  gchar ** (* callback_suggestions) (GladeSignalEditor *editor, GladeSignal *signal);
  gchar ** (* detail_suggestions) (GladeSignalEditor *editor, GladeSignal *signal);
  void   (* glade_reserved1)   (void);
  void   (* glade_reserved2)   (void);
  void   (* glade_reserved3)   (void);
  void   (* glade_reserved4)   (void);
};

GType              glade_signal_editor_get_type (void) G_GNUC_CONST;

GladeSignalEditor *glade_signal_editor_new                    (void);
void               glade_signal_editor_load_widget            (GladeSignalEditor *editor, 
							       GladeWidget       *widget);
GladeWidget       *glade_signal_editor_get_widget             (GladeSignalEditor *editor);

void glade_signal_editor_enable_dnd (GladeSignalEditor *editor, gboolean enabled);

G_END_DECLS

#endif /* __GLADE_SIGNAL_EDITOR_H__ */
