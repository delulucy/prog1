#include "../std_lib_facilities.h"


//3.feladat
template<typename T>
void kiirat(T v, char elv = ' '){
	for(auto& a : v)
		cout << a.first << elv << a.second << '\n';
}


//5.feladat
void beker(map<string, int>& m)
{
    string s;
    int k = 0;
        for(int i=1; i<11; i++){
        	cin >> s >> k;
       	m.insert(make_pair(s, i));
        }
    }

int main(){
	//1.feladat
	map<string,int> msi;
	
	//2.feladat
	msi["lecture"] = 21;
	msi["book"] = 20;
	msi["laptop"] = 64;
	msi["keyboard"] = 22;
	msi["pencil"] = 12;
	msi["spoon"] = 55;
	msi["headphones"] = 54;
	msi["bottle"] = 25;
	msi["lunchbox"] = 64;
	msi["glasses"] = 12;
	
	
	//3.feladat
	kiirat(msi);
	
	//4.feladat
	msi.erase(msi.begin(),msi.end());
	
	//6.feladat
	cout << "\nenter some (name, value) pairs\n";
	beker(msi);
	
	//7.feladat
	cout << "\ndata entered:\n";
	kiirat(msi);
	
	int sum = 0;
	for(auto& a : msi)
		sum +=  a.second;
	cout << "sum of the values: " << sum << '\n';
	
	map<int, string> mis;
	
	for (const auto& a : msi)
        mis[a.second] = a.first;
    	cout << "\nthe reversed version of the map:\n";
    	kiirat(mis);
}