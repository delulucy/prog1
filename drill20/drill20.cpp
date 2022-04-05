#include "std_lib_facilities.h"

ostream& print_array(ostream& os, int a[]){
	os << "Output of print_array: ";
	for (int i=0; i<10; i++)
		 os << a[i] << " ";
	os<<"\n";
	return os;
}

ostream& print_vector(ostream& os, vector<int> v){
	os << "Output of print_vector: ";
	for( auto& a : v)
		os << a << " ";
	os<<"\n";
	return os;
}

int main(){
	int array [10]= {0,1,2,3,4,5,6,7,8,9};
	print_array(cout,array);
	
	vector<int> vect(10);
	copy(array, array+10, vect.begin());
	print_vector(cout,vect);
	
	list<int> list(10);
	copy(array,array+10, list.begin());
	
	return 0;
}
