#include "Simple_window.h"
#include "Graph.h"
//g++ d13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
int main(){
	using namespace Graph_lib;
	
	Point tl{100,100};
	
	Simple_window win{tl,800,1000,"My window"};
	
	int x_size = win.x_max();
	int y_size = 800;
	int x_grid=100;
	int y_grid=100;
	
	Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	
	for(int y = y_grid; y<=y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

		
	Vector_ref<Rectangle> rects;
			
	int y_help=0;
			
	for(int x=0;x<x_size;x+=x_grid){
		for(int y=y_help;y<y_help+1;y+=2)
			rects.push_back(new Rectangle{Point(x,y),Point(x+x_grid,y+y_grid)});
		y_help+=y_grid;
		}
		
			
	
	for(int i=0;i<rects.size();++i){
		rects[i].set_fill_color(Color::red);
		rects[i].set_color(Color::invisible);
		win.attach(rects[i]);
		}

	win.attach(grid);
	
	
	win.wait_for_button();
	
	Image logo {Point{0,0},"kep.jpg"};
	win.attach(logo);
	
	for(int y=0;y<y_size;y+=y_grid);
	
	win.wait_for_button();
	
	
	
	
}
