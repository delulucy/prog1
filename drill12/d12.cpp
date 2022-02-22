#include "Simple_window.h"
#include "Graph.h"
//g++ d12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
int main(){
	using namespace Graph_lib;
	
	Point tl{100,100};
	
	Simple_window win{tl,600,400,"My window"};
	
	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
	xa.label.set_color(Color::dark_red);
	win.attach(xa);
	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	
	Function sine {sin,0,100,Point{20,300},1000,50,50};
	sine.set_color(Color::dark_red);
	win.attach(sine);
	
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.add(Point{350,150});
	
	poly.set_color(Color::blue);
	poly.set_style(Line_style(Line_style::dash,3));
	win.attach(poly);
	
	Rectangle r {Point{200,200}, 100,50};
	win.attach(r);
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	
	poly_rect.add(Point{75,75});
	
	r.set_fill_color(Color::cyan);
	poly.set_style(Line_style(Line_style::dash,5));
	poly_rect.set_style(Line_style(Line_style::dot,3));
	poly_rect.set_fill_color(Color::yellow);
	
	Text t {Point{250,20},"Hello, graphical world!"};
	win.attach(t);
	
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	
	/*Image img {Point{100,50},"badge.jpg"};
	win.attach(img);
	*/
	
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::white);
	Mark m{Point{100,200},'x'};
	win.attach(c);
	win.attach(m);
	win.attach(e);
	
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() << "; window size: " << 		win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,40},oss.str()};
	win.attach(sizes);
	
	
	
	win.wait_for_button();
}
