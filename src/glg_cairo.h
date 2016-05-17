/* $Id: glg_cairo.h,v 1.35 2007/07/25 16:41:07 jscott Exp $
 * ----------------------------------------------
 *
 * A GTK+ widget that implements a XY line graph
 *
 * (c) 2007, James Scott Jr 
 *
 * Authors:
 *   James Scott Jr <skoona@users.sourceforge.net>
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GLG_LINE_GRAPH_H__
#define __GLG_LINE_GRAPH_H__

G_BEGIN_DECLS

typedef struct _GlgLineGraph  GlgLineGraph;
typedef struct _GlgLineGraphClass GlgLineGraphClass;

/**
 * GlgLineGraphClass:
 * @point-selected: signal to return the y value under or near the mouse.
 * @graph: pointer to a #GlgLineGraph widget 
 * @x_value: x scale value
 * @y_value: y scale value
 * @point_y_pos: y value pixel position on chart
 * @mouse_y_pos: actual mouse y position on chart
 *  
 * Main widget Class structure
 */ 
struct _GlgLineGraphClass
{
	GtkDrawingAreaClass parent_class;

	void	(* point_selected)	(GtkWidget *graph, double x_value, double y_value, double point_y_pos, double mouse_y_pos);
};

/**
 * GlgLineGraph:
 *
 * Main widget structure
 */
struct _GlgLineGraph
{
	GtkDrawingArea parent;

	/* < private > */
};

/**
 * GLGElementID:
 * @GLG_TITLE_X:     Enables display of the top chart title
 * @GLG_NO_TITLE_X:  Disables display of the top chart title
 * 
 * Communication params for interface APIs
 */
typedef enum _GLG_Graph_Elements {
  /* enable chart flags and title keys */
  GLG_ELEMENT_NONE = 1 << 0,
  GLG_TITLE_X = 1 << 1,
  GLG_NO_TITLE_X = 0 << 1,
  GLG_TITLE_Y = 1 << 2,
  GLG_NO_TITLE_Y = 0 << 2,
  GLG_TITLE_T = 1 << 3,
  GLG_NO_TITLE_T = 0 << 3,

  /* enable chart attributes flag */  
  GLG_GRID_LABELS_X = 1 << 4,
  GLG_NO_GRID_LABELS_X = 0 << 4,
  GLG_GRID_LABELS_Y = 1 << 5,
  GLG_NO_GRID_LABELS_Y = 0 << 5,

  /* enable tooltip flag */
  GLG_TOOLTIP = 1 << 6,
  GLG_NO_TOOLTIP = 0 << 6,  
  
  /* enabled chart attributes */
  GLG_GRID_LINES   = 1 << 7,
  GLG_NO_GRID_LINES   = 0 << 7,
  GLG_GRID_MINOR_X = 1 << 8,
  GLG_NO_GRID_MINOR_X = 0 << 8,
  GLG_GRID_MAJOR_X = 1 << 9,
  GLG_NO_GRID_MAJOR_X = 0 << 9,
  GLG_GRID_MINOR_Y = 1 << 10,
  GLG_NO_GRID_MINOR_Y = 0 << 10,
  GLG_GRID_MAJOR_Y = 1 << 11,
  GLG_NO_GRID_MAJOR_Y = 0 << 11,
  
  /* chart color key -- used to change window color only */
  GLG_SCALE   = 1 << 12,  
  GLG_TITLE   = 1 << 13,
  GLG_WINDOW  = 1 << 14,  
  GLG_CHART   = 1 << 15, 

  /* Reserved */   
  GLG_RESERVED_OFF = 0 << 16,
  GLG_RESERVED_ON  = 1 << 16      
} GLGElementID;

#define GLG_TYPE_LINE_GRAPH			(glg_line_graph_get_type ())
#define GLG_LINE_GRAPH(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GLG_TYPE_LINE_GRAPH, GlgLineGraph))
#define GLG_LINE_GRAPH_CLASS(obj)	(G_TYPE_CHECK_CLASS_CAST ((obj), GLG_LINE_GRAPH, GlgLineGraphClass))
#define GLG_IS_LINE_GRAPH(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GLG_TYPE_LINE_GRAPH))
#define GLG_IS_LINE_GRAPH_CLASS(obj)	(G_TYPE_CHECK_CLASS_TYPE ((obj), GLG_TYPE_LINE_GRAPH))
#define GLG_LINE_GRAPH_GET_CLASS	(G_TYPE_INSTANCE_GET_CLASS ((obj), GLG_TYPE_LINE_GRAPH, GlgLineGraphClass))


/* 
 * Public Interfaces 
*/
extern GlgLineGraph *  glg_line_graph_new (void);
extern GType    glg_line_graph_get_type  (void) G_GNUC_CONST;
extern void 		glg_line_graph_redraw (GlgLineGraph *graph);
extern GLGElementID glg_line_graph_chart_get_elements ( GlgLineGraph *graph);
extern void 		glg_line_graph_chart_set_elements ( GlgLineGraph *graph, GLGElementID element);
extern gboolean 	glg_line_graph_chart_set_text  (GlgLineGraph *graph, GLGElementID element, const gchar *pch_text);
extern gboolean 	glg_line_graph_chart_set_color (GlgLineGraph *graph, GLGElementID element, const gchar *pch_color);  
extern void 		glg_line_graph_chart_set_ranges (GlgLineGraph *graph,
                                 gint x_tick_minor, gint x_tick_major,
                                 gint x_scale_min,  gint x_scale_max,
                                 gint y_tick_minor, gint y_tick_major, 
                                 gint y_scale_min,  gint y_scale_max);
extern void glg_line_graph_chart_set_x_ranges (GlgLineGraph *graph,
                                 gint x_tick_minor, gint x_tick_major,
                                 gint x_scale_min,  gint x_scale_max);
extern void glg_line_graph_chart_set_y_ranges (GlgLineGraph *graph,
                                 gint y_tick_minor, gint y_tick_major,
                                 gint y_scale_min,  gint y_scale_max);


extern gint 		glg_line_graph_data_series_add (GlgLineGraph *graph, const gchar *pch_legend_text, const gchar *pch_color_text);
extern gboolean 	glg_line_graph_data_series_add_value (GlgLineGraph *graph, gint i_series_number, gdouble y_value);

G_END_DECLS

#endif
