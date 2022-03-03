#include "Simple_window.h"
#include "Graph.h"
//g++ d13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
int main(){
	using namespace Graph_lib;
	
	//1.
	Point tl{100,100};
	
	Simple_window win{tl,800,1000,"My window"};

	win.wait_for_button();
	
	//2.
	int x_size = win.x_max();
	int y_size = 800;
	int x_grid=100;
	int y_grid=100;
	
	Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	
	for(int y = y_grid; y<=y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});

	win.attach(grid);

	win.wait_for_button();

	//3.
	Vector_ref<Rectangle> rects;		
	for(int i=0; i< x_size; i+=x_grid){
		rects.push_back(new Rectangle{Point{i,i},Point{i+x_grid,i+x_grid}});
		rects[rects.size()-1].set_fill_color(Color::red);
		rects[rects.size()-1].set_color(Color::invisible);
		win.attach(rects[rects.size()-1]);
	}	
			
	win.wait_for_button();

	//4. 
	Image img1 {Point{300,600},"image2.jpeg"};
	Image img2 {Point{0,200},"image2.jpeg"};
	Image img3 {Point{600,400},"image2.jpeg"};
	
	win.attach(img1);
	win.attach(img2);
	win.attach(img3);
	win.wait_for_button();

	//5.
	Image eye {Point{0,0},"image.jpeg"};
	int y_eyeTopLeft=0;
	win.attach(eye);
	win.wait_for_button();

	for(int i= 1; i<9;++i){
		for(int j=1;j<8;++j){
			eye.move(100,0);
			win.wait_for_button();
		}
		y_eyeTopLeft+=100;
		if(y_eyeTopLeft==800)
			break;
		eye.move(-700,100);
		win.wait_for_button();
	}
	
}
