#include <iostream>
#include <string>
using namespace std;
#include "libary_BigNumber.h"
int main()
{
	menu();
	int chon;
	cin>>chon;
	if(chon==1)
	{
		string a;
		string b;
		cin>> a;
		cin>> b;
		add(a,b);
		cout<<endl;
	}
	if(chon==2)
	{
		string a;
		string b;
		cin>> a;
		cin>> b;
		sub(a,b);
		cout<<endl;
	}
	if(chon==3)
	{
		string a;
		string b;
		cin>> a;
		cin>> b;
		cout<<nhan(a,b);
		cout<<endl;
	}
	return 0;
}
