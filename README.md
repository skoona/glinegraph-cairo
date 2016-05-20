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
			'# ./autogen.sh --enable-gtk-doc '
			'# make clean '
			'# make '
			'# make install'

			'# ./configure '
			'# make clean '
			'# make '
			'# make install'

INSTRUCTIONS: 

  glinegraph -- GTK+ Cairo Programing Example Application
    
    1. Compile program
	2. Execute sample program
		- regular cmd: "# lgcairo" 


KNOWN BUGS:

    Current version has a major performance bug when drawing with Cairo.  Researching the Failure now.
    First noticed on OSX, then Raspbian, Fedora, and Ubuntu.
    Related to 'Draw' signal and cairo surface used for painting: first pass 4ms, each pass adds 300ms more
    until the time to draw is greater than the arrival on new data points, causing a draw backlog.
	
	Not sure if it is a GTK3 issue or not Gtk 3.10 sufferes, Gtk 3.16 is reasonable, Gtk 3.18 also suffers.



BEGIN DEBUG LOG: 

### To see console log -- $ export G_MESSAGES_DEBUG=all

		[jscott@jscott5365m OSX El-Capitan GLG-Cairo]$ pkg-config --modversion gtk+-3.0
		3.16.6
		
		[jscott@jscott5365m OSX El-Capitan glinegraph-cairo]$ src/lgcairo 

		** (lgcairo:51717): DEBUG: ===> glg_line_graph_class_init()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_init()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_color()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_color()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_color()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_color()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_text()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_text()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_set_property()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_chart_set_text()
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAdd: series=0, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAdd: series=1, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAdd: series=2, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAdd: series=3, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAdd: series=4, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_size_allocate(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_compute_layout(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_compute_layout(new width=540, height=260)
		** (lgcairo:51717): DEBUG: Alloc:factors:raw:pango_layout_get_pixel_size(width=10, height=12)
		** (lgcairo:51717): DEBUG: Alloc:factors:adj:pango_layout_get_pixel_size(width=10, height=20)
		** (lgcairo:51717): DEBUG: Alloc:Max.Avail: plot_box.width=470, plot_box.height=165
		** (lgcairo:51717): DEBUG: Alloc:Chart:Incs:    x_minor=9, x_major=45, y_minor=3, y_major=15, plot_box.x=76, plot_box.y=50, plot_box.width=450, plot_box.height=165
		** (lgcairo:51717): DEBUG: Alloc:Chart:Nums:    x_num_minor=50, x_num_major=10, y_num_minor=55, y_num_major=11
		** (lgcairo:51717): DEBUG: Alloc:Chart:Plot:    x=76, y=50, width=450, height=165
		** (lgcairo:51717): DEBUG: Alloc:Chart:Title:   x=76, y=5, width=450, height=40
		** (lgcairo:51717): DEBUG: Alloc:Chart:yLabel:  x=5, y=215, width=30, height=140
		** (lgcairo:51717): DEBUG: Alloc:Chart:xLabel:  x=76, y=230, width=450, height=25
		** (lgcairo:51717): DEBUG: Alloc:Chart:Tooltip: x=76, y=5, width=450, height=45
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_compute_layout(exited)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_size_allocate(exited) rc=True
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_configure_event(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.225 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=29.116 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=7.649 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=8.101 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.347 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=20.363 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.237 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=0.012 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=0.050 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=66.201 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_configure_event(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=2.026 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=2.698 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=18.7, index=0, count=1, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=27.0, index=0, count=1, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=1, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=94.8, index=0, count=1, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.4, index=0, count=1, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.305 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.401 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.217 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.381 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.447 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.437 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.366 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=3.606 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=2.910 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=2.648 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=2.423 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=2.179 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=13.828 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=16.481 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.201 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.692 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=17.2, index=0, count=2, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=26.3, index=0, count=2, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=2, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=62.1, index=0, count=2, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.1, index=0, count=2, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.299 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.371 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.217 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.395 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.442 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.421 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.363 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=7.227 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=5.381 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=4.570 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=4.250 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=4.563 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=26.047 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.003 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=28.658 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.236 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=16.4, index=0, count=3, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=27.5, index=0, count=3, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=3, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=6.5, index=0, count=3, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.6, index=0, count=3, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.293 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.367 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.213 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.375 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.430 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.412 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.353 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=10.628 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=7.655 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=7.245 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=6.555 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=8.298 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=40.471 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=43.016 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.224 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=18.0, index=0, count=4, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=22.2, index=0, count=4, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=4, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=87.0, index=0, count=4, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.4, index=0, count=4, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.299 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.360 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.214 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.375 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.433 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.418 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.394 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=13.392 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=9.674 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=10.304 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=9.636 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=11.059 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=54.163 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=56.773 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.243 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=7.1, index=0, count=5, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=22.7, index=0, count=5, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=5, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=35.7, index=0, count=5, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.9, index=0, count=5, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.203 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.311 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.186 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.250 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.263 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.238 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.203 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=13.820 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=13.801 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=14.365 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=11.642 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=13.612 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=67.378 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=69.105 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.206 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=6.0, index=0, count=6, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=24.3, index=0, count=6, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=6, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=39.8, index=0, count=6, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.2, index=0, count=6, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.300 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.351 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.216 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.404 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.465 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.260 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.193 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=16.013 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=16.383 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=17.662 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=14.152 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=17.310 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=81.642 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=83.930 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.209 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=9.4, index=0, count=7, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=29.1, index=0, count=7, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=7, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=75.4, index=0, count=7, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.2, index=0, count=7, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.154 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.221 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.128 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.266 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.302 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.360 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.353 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=19.023 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=21.085 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=20.924 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=18.251 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=20.342 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=99.750 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=101.616 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.392 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=16.4, index=0, count=8, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=23.1, index=0, count=8, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=8, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=61.2, index=0, count=8, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.7, index=0, count=8, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.288 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.354 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.216 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.386 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.438 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.338 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.272 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=21.919 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=24.266 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=25.391 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=21.813 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=26.448 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=119.955 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=122.348 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.188 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=18.2, index=0, count=9, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=25.6, index=0, count=9, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=9, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=35.0, index=0, count=9, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.5, index=0, count=9, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.204 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.253 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.124 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.251 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.284 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.271 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.214 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=25.255 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=24.218 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=27.435 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=25.599 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=28.801 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=131.449 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=133.131 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.182 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=11.1, index=0, count=10, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=24.2, index=0, count=10, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=10, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=54.9, index=0, count=10, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.5, index=0, count=10, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.449 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.371 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.214 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.374 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.431 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.407 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.352 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=28.216 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=33.062 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=31.172 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=26.844 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=31.215 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=150.668 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=153.386 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.200 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=7.5, index=0, count=11, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=29.8, index=0, count=11, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=11, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=73.5, index=0, count=11, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.4, index=0, count=11, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.255 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.331 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.197 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.303 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.439 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.290 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.194 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=34.322 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=36.516 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=43.439 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=27.415 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=39.513 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=181.388 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=183.482 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.429 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=10.2, index=0, count=12, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=22.5, index=0, count=12, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=12, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=33.9, index=0, count=12, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.7, index=0, count=12, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.680 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.343 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.142 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.250 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.309 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.517 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.250 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=33.404 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=36.810 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=40.915 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=31.959 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=48.879 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=192.138 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.012 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=194.745 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.214 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=8.8, index=0, count=13, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=20.8, index=0, count=13, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=13, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=37.0, index=0, count=13, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.8, index=0, count=13, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.238 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.289 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.183 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.271 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.247 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.228 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.189 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=35.934 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=36.188 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=40.420 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=31.140 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=62.849 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=206.653 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.006 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=208.376 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.323 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=15.6, index=0, count=14, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=22.3, index=0, count=14, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=14, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=67.1, index=0, count=14, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.8, index=0, count=14, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.157 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.218 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.113 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.201 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.262 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.220 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.186 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=39.141 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=44.774 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=50.765 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=37.410 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=54.654 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=226.875 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.004 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=228.294 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.432 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=12.2, index=0, count=15, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=20.1, index=0, count=15, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=15, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=93.1, index=0, count=15, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.5, index=0, count=15, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.313 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.358 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.192 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.315 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.336 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.434 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.290 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=44.388 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=53.217 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=56.320 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=43.142 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=62.798 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=260.011 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.006 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=262.349 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.849 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=10.5, index=0, count=16, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=20.1, index=0, count=16, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=16, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=23.6, index=0, count=16, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.0, index=0, count=16, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.259 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.350 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.208 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.376 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.434 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.421 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.371 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=46.288 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=48.181 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=53.722 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=39.321 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=49.569 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=237.203 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=239.726 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.586 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=8.4, index=0, count=17, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=26.5, index=0, count=17, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=17, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=93.2, index=0, count=17, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=99.2, index=0, count=17, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.159 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.216 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.115 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.220 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.236 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.227 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.197 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=50.581 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=55.042 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=57.109 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=42.219 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=54.940 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=260.009 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.006 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=261.442 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.243 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=0, value=10.3, index=0, count=18, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=1, value=27.8, index=0, count=18, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=2, value=82.7, index=0, count=18, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=3, value=57.1, index=0, count=18, max_pts=100
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_add_value()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesAddValue: series=4, value=98.1, index=0, count=18, max_pts=100
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(entered)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#PlotArea() duration=0.306 ms.
		** (lgcairo:51717): DEBUG: Chart.Surface: pg.Width=540, pg.Height=260, Plot Area x=76 y=50 width=450, height=165
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=5, cx=450, cy=40
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=187, y_pos=8,  cx=228, cy=36
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Top-Title() duration=0.354 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_horizontal()
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Page cx=540, cy=260
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Orig: x=76, y=230, cx=450, cy=25
		** (lgcairo:51717): DEBUG: Horiz.TextBox:Calc x_pos=155, y_pos=237,  cx=291, cy=16
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Title() duration=0.213 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_text_vertical()
		** (lgcairo:51717): DEBUG: Vert:TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: Vert.TextBox: y_pos=239,  x=5, y=215, cx=218, cy=30
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Title() duration=0.390 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_grid_lines()
		** (lgcairo:51717): DEBUG: Draw.Y-GridLines: count_major=10, count_minor=54, y_minor_inc=3, y_major_inc=15
		** (lgcairo:51717): DEBUG: Draw.X-GridLines: count_major=9, count_minor=49, x_minor_inc=9, x_major_inc=45
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#GridLines() duration=0.436 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_x_grid_labels()
		** (lgcairo:51717): DEBUG: Scale:Labels:X small font sizes cx=20, cy=11
		** (lgcairo:51717): DEBUG: Scale:Labels:X plot_box.cx=450, layout.cx=470, layout.cy=11
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#X-Labels() duration=0.425 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_y_grid_labels()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Y-Labels() duration=0.401 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw_all(entered)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[0]Series() duration=59.522 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[1]Series() duration=60.538 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[2]Series() duration=63.971 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[3]Series() duration=50.317 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_draw()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_data_series_draw#[4]Series() duration=64.293 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_data_series_draw_all(exited): #series=5
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Series-All() duration=298.772 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_tooltip()
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#Tooltip() duration=0.005 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_draw_graph(exited)
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_draw_graph#TOTAL-TIME() duration=301.403 ms.
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_redraw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_master_draw(entered)
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(Allocation ==> width=540, height=260,  Dirty Rect ==> x=0, y=0, width=540, height=260 )
		** (lgcairo:51717): DEBUG: DURATION: glg_line_graph_master_draw#TOTAL-TIME() duration=1.348 ms.
		** (lgcairo:51717): DEBUG: glg_line_graph_master_draw(exited)
		
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_destroy(enter)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_data_series_remove_all()
		** (lgcairo:51717): DEBUG:   ==>DataSeriesRemoveAll: number removed=5
		** (lgcairo:51717): DEBUG: glg_line_graph_destroy(exit)
		** (lgcairo:51717): DEBUG: ===> glg_line_graph_destroy(enter)
		** (lgcairo:51717): DEBUG: glg_line_graph_destroy(exit)

END DEBUG LOG:
 	
