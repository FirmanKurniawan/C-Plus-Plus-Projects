#include <iostream>
using namespace std;

int main (){
	int i = 9;
	cout<<i<<endl;
	cout<<&i<<endl;
	int *x;
	x = &i;
	char t;
	cout<<x<<endl;
	cout<<*x<<endl;
	cout<<&x<<endl;
	cout<<sizeof(x)<<endl;
	cout<<sizeof(t)<<endl;
	
	int z = (i>7)?300:700;
	cout<<z;
}
