#include "../std_lib_facilities.h"
#include <list>

//1.feladat
struct Item { 
	string name; 
	int iid; 
	double value;

};

istream& operator>>(istream& is, Item& it){
	is >> it.name >> it.iid >> it.value;
	Item {it.name,it.iid,it.value};
	return is;
}

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << ' '
              << it.iid << ' '
              << it.value;
}


template<typename T>
void print(T v, char elv = ' '){
	for(auto& a : v){
		cout << a << elv << '\n';
	}
}


//2.feladat
struct by_name{
	bool operator()(Item& it1, Item& it2)
			{ return it1.name < it2.name;}
};

//3.feladat
struct by_iid{
	bool operator()(Item& it1, Item& it2)
			{ return it1.iid < it2.iid;}
};

//4.feladat
struct by_value_desc{
	bool operator()(Item& it1, Item& it2)
			{ return it1.value > it2.value;}
};


//6.feladat
class delete_by_name{
    string name;
public:
    delete_by_name(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};


//7.feladat
class delete_by_iid {
    int iid;
public:
    delete_by_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};


int main(){
	//1
	vector<Item> vi;
	
	ifstream ifile {"stuff.txt"};
	for(Item it; ifile >> it;){//while(ifile >> it.name >> it.iid >> it.value){
		vi.push_back(it);//Item {it.name,it.iid,it.value});
	}
	cout << "the vector:\n";
	print(vi);

	ifile.close();
	//2
	sort(vi.begin(),vi.end(),by_name());
		//[](Item& f1, Item& f2){return f1.name < f2.name;});
	cout << "\nthe vector ordered by name:\n";
	print(vi);
	
	//3
	sort(vi.begin(),vi.end(),by_iid());
	cout << "\nthe vector ordered by iid:\n";
	print(vi);

	//4
	sort(vi.begin(),vi.end(),by_value_desc());
	cout << "\nthe vector ordered by value (descending):\n";
	print(vi);

	//5
	vi.push_back(Item {"horse shoe",99,12.34}); 
	vi.push_back(Item {"Canon S400", 9988,499.95});
	cout << "\nthe vector after adding the data:\n";
	print(vi);
	
	
	// 6.
	vi.erase(find_if(vi.begin(), vi.end(), delete_by_name("knife")));
	vi.erase(find_if(vi.begin(), vi.end(), delete_by_name("phone")));
	
	// 7.
	vi.erase(find_if(vi.begin(), vi.end(), delete_by_iid(10)));
	vi.erase(find_if(vi.begin(), vi.end(), delete_by_iid(76)));
	
	cout << "\nthe vector after deleting the data:\n";
	print(vi);
	
	
	
	
	//8
	
	list<Item> li;
	ifile.open("stuff.txt");
	for(Item it; ifile >> it;) li.push_back(it);
	cout << "\nthe list:\n";
	print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
	cout << "\nthe list ordered by name: \n";
	print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
	cout << "\nthe list ordered by iid:";
	print(li);
	
	li.sort([](const Item& a, const Item& b) { return a.value > b.value; });
	cout << "\nthe list ordered by value (descending):\n";
	print(li);
	
	li.push_back(Item {"horse shoe",99,12.34}); 
	li.push_back(Item {"Canon S400", 9988,499.95});
	
	cout << "\nthe list after adding the data:\n";
	print(li);
	
	li.erase(find_if(li.begin(), li.end(), delete_by_name("knife")));
	li.erase(find_if(li.begin(), li.end(), delete_by_name("phone")));

	li.erase(find_if(li.begin(), li.end(), delete_by_iid(10)));
	li.erase(find_if(li.begin(), li.end(), delete_by_iid(76)));
	
	cout << "\nthe list after deleting the data:\n";
	print(li);
}