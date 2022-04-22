#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include "complex"
#include "numeric"

using namespace Numeric_lib;

void squareroot()
{
	int input;
	cout << "enter an integer: ";	
	cin >> input;
	if (input<0)
		cout << "no square root" << "\n";
	else
		cout << "the square root of " << input << " is " << sqrt(input) << "\n";
}

int main()
{
	try
	{
	//1.feladat
	cout << "sizes of data types:";
	cout << "char: " << sizeof(char) << "\n";
	cout << "short: " << sizeof(short) << "\n";
	cout << "int: " << sizeof(int) << "\n";
	cout << "long: " << sizeof(long) << "\n";
	cout << "float: " << sizeof(float) << "\n";
	cout << "double: " << sizeof(double) << "\n";
	cout << "int*: " << sizeof(int*) << "\n";
	cout << "double*: " << sizeof(double*) << "\n";
	cout << "\n";

	//2.feladat
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	cout << "the sizes of matrixes";
	cout << "Matrix<int> a(10): " << sizeof(a) << "\n";
	cout << "Matrix<int> b(100): " << sizeof(b) << "\n";
	cout << "Matrix<double> c(10): " << sizeof(c) << "\n";
	cout << "Matrix<int,2> d(10,10): " << sizeof(d) << "\n";
	cout << "Matrix<int,3> e(10,10,10): " << sizeof(e) << "\n";
	cout << "\n";

	//3.feladat
	cout << "number of elements in each of the matrixes:";
	cout << "Matrix<int> a(10): " << a.size() << "\n";
	cout << "Matrix<int> b(100): " << b.size() << "\n";
	cout << "Matrix<double> c(10): " << c.size() << "\n";
	cout << "Matrix<int,2> d(10,10): " << d.size() << "\n";
	cout << "Matrix<int,3> e(10,10,10): " << e.size() << "\n";
	cout << "\n";

	//4.feladat
	squareroot();

	//5.feladat
	Matrix<double>tendoubles(10);
	cout << "enter ten doubles " << "\n";
	float f_input=0;
	for (int i=0;i<10;i++)
		{
		cin>>tendoubles(i);
		}
	cout << tendoubles << "\n";
	cout << "\n";
	
	//6.feladat
	int n,m;
	cout << "enter the dimensions of the multiplication table: " << "\n";
	cin>>n>>m;
	
	Matrix<double,2> m_table(n,m);

	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			m_table(i,j)=i*j;

	for (int i=0;i<n;i++)
		{
		for (int j=0;j<m;j++)
			cout << m_table(i,j) << ' ';

		cout << "\n";
		}
	
	//7.feladat
	Matrix<complex<double>>c_matrix(10);

	cout << "enter ten complex numbers: " << "\n";

	for (int i=0;i<10;i++)
		{
		cin>>c_matrix(i);
		}

	cout << c_matrix << "\n";

	complex<double> sum=accumulate(c_matrix.data(),c_matrix.data()+c_matrix.size(),complex<double>{});
	cout << sum << "\n";
	
	//8.feladat
	Matrix<int,2>six_m(2,3);
	cout << "enter 6 integers: " << "\n";

	for (int i=0;i<2;i++)
		for (int j=0;j<3;j++)
			cin>>six_m(i,j);

	cout << six_m << "\n";
	
	for (int i=0;i<2;i++)
		{
		for (int j=0;j<3;j++)
			cout << six_m(i,j) << ' ';

		cout << "\n";
		}	

	return 0;
	}
	catch(exception& e)
	{
	cerr  <<  "error: "  <<  e.what()  <<  '\n'; 
	return 1;
	}
	catch(...)
	{
	cerr  <<  "exception unknown"  <<  '\n'; 
	return 2;
	}
}