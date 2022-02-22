#include "Simple_window.h"
#include "Graph.h"
//g++ d12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
int main(){
	using namespace Graph_lib;
	
	Point tl{100,100};
	
	Simple_window win{tl,600,400,"My window"};
	
	win.wait_for_button();
}
