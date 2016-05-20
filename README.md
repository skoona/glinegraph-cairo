#GlgLineGraph
### (a.k.a cairo version of glinegraph )  July 2007/2016

![GLineGraph Widget](https://github.com/skoona/glinegraph-cairo/raw/master/glg_cairo.png) 

 A Gtk3/GLib2/cario GUI application which demonstrates the use of GTK+ for producing xy line graphs.  This widget once created allows you to add one or more data series, then add values to those series for ploting.  The X point is assumed based on arrival order.  However, the Y value or position is based one the current scale and the y value itself.  If the charts x scale maximum is 40, or 40 points, the 41+ value is appended to the 40th position after all points are shifted left and out through pos 0.
 
 Packaged as a gtk widget for ease of use.	

 A lgcairo.c example program is included to demonstrate the possible use of the codeset.

There is also gtk-style API documentation in ./src/docs/reference/html/index.html

FEATURES: 

    * GlgLineGraph API Reference Manual in ./src/docs/reference/html/index.html
    * Unlimited data series support.
    * Accurate scaling across a wide range of X & Y scales.
      - Using values ranges above or below 1.
    * Rolling data points, if number of x points exceed x-scale. (left shift)
    * Ability to change chart background color, window backgrounds colors, etc.
    * Popup Tooltip, via mouse-button-1 click to enable/toggle.
      - Tooltip overlays top graph title, when present.
    * Data points are time stamped with current time when added.
	* Some key debug messages to console with button-3 enable, then button-2 click/toggle.
	* Auto Size to current window size; i.e. no-scrolling.
	* point-selected signal tied to tooltip, to display y value under mouse.

REQUIREMENTS:

	Gtk3/Glib2 runtime support. (Created on Fedora Core 6)

	* the following packages may need to be installed to build program and
	  for runtime of binaries on some platforms.

	glinegraph - { this package }
	gtk-devel  - { GTK+ version 3.10 is minimum package level required}
	glib-devel - { version 2.40, packaged with GTK+ } 
						 		

DISTRIBUTION METHOD:

	Source tar	glinegraph-{version}.tar.bz2
	GPL2 copyright

INSTALL INFO:
	Configure Source with 
			'# ./autogen.sh '
			'# make '
			'#sudo make install'

INSTRUCTIONS: 

  glinegraph -- GTK+ Cairo Programing Example Application
    
    1. Compile program
	2. Execute sample program
		- regular cmd: "# lgcairo" 


KNOWN BUGS:

    Gtk+-3.10.0 has a major performance bug when drawing with Cairo.  Researching the Failure now.
    First noticed on OSX, then Raspbian, Fedora, and Ubuntu.
    Related to 'Draw' signal and cairo surface used for painting: first pass 4ms, each pass adds 300ms more
    until the time to draw is greater than the arrival on new data points, causing a draw backlog.



BEGIN DEBUG LOG: to see console log -- $ export G_MESSAGES_DEBUG=all

[jscott@imac glinegraph-cairo]$ src/lgcairo 

	** (lgcairo:6489): DEBUG: ===> glg_line_graph_class_init()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_init()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_color()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_color()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_color()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_color()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_text()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_text()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_set_property()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_chart_set_text()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_configure_event(entered)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_configure_event(new width=540, height=260)
	** (lgcairo:6489): DEBUG: cfg:factors:raw:pango_layout_get_pixel_size(width=10, height=12)
	** (lgcairo:6489): DEBUG: cfg:factors:adj:pango_layout_get_pixel_size(width=10, height=20)
	** (lgcairo:6489): DEBUG: cfg:Max.Avail: plot_box.width=470, plot_box.height=165
	** (lgcairo:6489): DEBUG: cfg:Chart:Incs:    x_minor=9, x_major=45, y_minor=3, y_major=15, plot_box.x=76, plot_box.y=50, plot_box.width=450, plot_box.height=165
	** (lgcairo:6489): DEBUG: cfg:Chart:Nums:    x_num_minor=50, x_num_major=10, y_num_minor=55, y_num_major=11
	** (lgcairo:6489): DEBUG: cfg:Chart:Plot:    x=76, y=50, width=450, height=165
	** (lgcairo:6489): DEBUG: cfg:Chart:Title:   x=76, y=5, width=450, height=40
	** (lgcairo:6489): DEBUG: cfg:Chart:yLabel:  x=5, y=215, width=30, height=140
	** (lgcairo:6489): DEBUG: cfg:Chart:xLabel:  x=76, y=230, width=450, height=25
	** (lgcairo:6489): DEBUG: cfg:Chart:Tooltip: x=76, y=5, width=450, height=45
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_configure_event(exited)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAdd: series=0, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAdd: series=1, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAdd: series=2, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAdd: series=3, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAdd: series=4, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=0, value=7.7, index=0, count=1, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=1, value=19.5, index=0, count=1, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=1, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=3, value=58.7, index=0, count=1, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=4, value=100.0, index=0, count=1, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_redraw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=0, value=7.7, index=0, count=2, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=1, value=19.5, index=0, count=2, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=2, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=3, value=19.3, index=0, count=2, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_add_value()
	** (lgcairo:6489): DEBUG:   ==>DataSeriesAddValue: series=4, value=100.0, index=0, count=2, max_pts=100
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_redraw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_expose(entered)
	** (lgcairo:6489): DEBUG: glg_line_graph_expose(width=540, height=260)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw(entered)
	** (lgcairo:6489): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_text_horizontal()
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Page cx=540, cy=260
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_text_horizontal()
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Page cx=540, cy=260
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_text_vertical()
	** (lgcairo:6489): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
	** (lgcairo:6489): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_grid_lines()
	** (lgcairo:6489): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
	** (lgcairo:6489): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
	** (lgcairo:6489): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
	** (lgcairo:6489): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_tooltip()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw(exited)
	** (lgcairo:6489): DEBUG: glg_line_graph_expose(exited)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_configure_event(entered)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_configure_event(new width=540, height=260)
	** (lgcairo:6489): DEBUG: cfg:factors:raw:pango_layout_get_pixel_size(width=10, height=12)
	** (lgcairo:6489): DEBUG: cfg:factors:adj:pango_layout_get_pixel_size(width=10, height=20)
	** (lgcairo:6489): DEBUG: cfg:Max.Avail: plot_box.width=470, plot_box.height=165
	** (lgcairo:6489): DEBUG: cfg:Chart:Incs:    x_minor=9, x_major=45, y_minor=3, y_major=15, plot_box.x=76, plot_box.y=50, plot_box.width=450, plot_box.height=165
	** (lgcairo:6489): DEBUG: cfg:Chart:Nums:    x_num_minor=50, x_num_major=10, y_num_minor=55, y_num_major=11
	** (lgcairo:6489): DEBUG: cfg:Chart:Plot:    x=76, y=50, width=450, height=165
	** (lgcairo:6489): DEBUG: cfg:Chart:Title:   x=76, y=5, width=450, height=40
	** (lgcairo:6489): DEBUG: cfg:Chart:yLabel:  x=5, y=215, width=30, height=140
	** (lgcairo:6489): DEBUG: cfg:Chart:xLabel:  x=76, y=230, width=450, height=25
	** (lgcairo:6489): DEBUG: cfg:Chart:Tooltip: x=76, y=5, width=450, height=45
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_configure_event(exited)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_expose(entered)
	** (lgcairo:6489): DEBUG: glg_line_graph_expose(width=540, height=260)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw(entered)
	** (lgcairo:6489): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_text_horizontal()
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Page cx=540, cy=260
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_text_horizontal()
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Page cx=540, cy=260
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
	** (lgcairo:6489): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_text_vertical()
	** (lgcairo:6489): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
	** (lgcairo:6489): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_grid_lines()
	** (lgcairo:6489): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
	** (lgcairo:6489): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
	** (lgcairo:6489): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
	** (lgcairo:6489): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_data_series_draw()
	** (lgcairo:6489): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw_tooltip()
	** (lgcairo:6489): DEBUG: ===> glg_line_graph_draw(exited)
	** (lgcairo:6489): DEBUG: glg_line_graph_expose(exited)

END DEBUG LOG:
 	
