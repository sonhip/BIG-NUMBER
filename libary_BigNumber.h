#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define RED		"\033[31m"
#define BLUE	"\033[34m"
#define WHITE	"\033[37m"
#define YELLOW  "\033[33m"

int get(char x)// ham chuyen doi mot ki tu thanh mot so
{
	return int(x-48);
}

//---------------------------------------------------------------------------------------------------------------------------------------//

void sosanh(string &a, string &b)// so sanh do dai ki tu cua 2 xau
{
	int szA=a.size();
	int szB=b.size();
	if (szA>szB)
		b=string(szA-szB, '0')+b;//them ki tu 0 vao xau co do dai ngan hon
	else 
		a=string(szB-szA, '0')+a;
}

//---------------------------------------------------------------------------------------------------------------------------------------//

void add(string a, string b)//cong hai so chuoi
{
	sosanh(a,b);
	int n=0;
	string tong;
	for (int i=a.size()-1;i>=0;i--)
	{
		int x=get(a[i]);
		int y=get(b[i]);
		int z= x+y+n;
		if (z>9)
		{
			z=z%10;
			n=1;
		}
		else
			n=0;
		tong=char(z+48)+tong;
	}
	if (get(a[0])+get(b[0])+n>9)//them ki tu 1 vao dau chuoi neu tong lon hon 9
		tong='1'+tong;
	cout<<tong;
}

//---------------------------------------------------------------------------------------------------------------------------------------//


string sub(string a, string b)
{
	sosanh(a,b);
	string hieu="";
	int n=0;
	for(int i=a.size()-1;i>=0;i--)
	{
		int z= get(a[i])-get(b[i])-n;
		n=0;
		if(z>=0)
		{	
			hieu=(string (1,(char) z + 48)) + hieu;//chuyen so sang ki tu roi them vao xau hieu
		}
		else
		{
			z = (get(a[i]) +10 )- get(b[i])-n ;//cong them 10 vao ch so tru roi tru,chuyen so sang ki tu roi them vao xau hieu
			n=1;
			hieu= (string (1,(char) z + 48)) + hieu;
		}	
	}
	return hieu;
}

//----------------------------------------------------------------------------------------------------------------------------------------//
void menu()
{

	cout<<RED<<"\n\n\t\t===============BIG NUMBER===============";
	cout<<WHITE<<"\n\n\t\t====================================";
	cout<<WHITE<<"\n1.PLUS";
	cout<<WHITE<<"\n2.MINUS";
	cout<<WHITE<<"\n3.MULTIPLICATION";
}


//-------------------------------------------------------------------------------------------------------------------------------------//
//phần này chưa rõ,hiện đang tham khảo bạn bè//

string big;
char num;

string mul10(string a)
{
	return a+"0";
}
string devideby10(string a)
{
	
	return a.erase(a.size()-1);
}



string cungsize2(string &a, string &b)
{
	int sa=a.size();
	int sb=b.size();
	if (sa>sb)
	{
		string x(sa-sb, '0')	;
		b=x+b;
		return b;
		
	}	
	else
	{
	
		string x(sb-sa, '0');
		a=x+a;
		return a;
	}	
}





string plus_big(string a, string b)
{
	cungsize2(a,b);
	string sum1,total;
	int nho =0;
	for (int i=a.size()-1; i>=0; i--)
	{
		int z=((int ) a[i] -48) + ((int) b[i] - 48) + nho;
		
		if (z>=10)
		{
			z=z%10;
			nho=1;
			sum1 =  char (z +48) ;
		}
		else
		{
			nho=0;
			sum1 = char( z +48) ;
		}
		total = sum1 + total;
	}
	string x;
	if (nho==1)
		x="1";
	return x+total;
}
string nhan1with1(string big,char num);

string nhan(string a, string b)
{
	{	
		if(b.size()==1)
			return(nhan1with1(a,b[0]));
		else
		{
			string s=nhan(a,devideby10(b));
			s = mul10(s);
			s = plus_big(s, nhan1with1(a, b[b.size()-1]));
			return s;
		}
	}		


}
string nhan1with1(string big,char num)
{
	int z=num-48;
	int nho=0;
	string result;
	for (int i= big.size()-1; i>=0;i--)
	{
		int cv=big[i]-48;
		int temp= (z * cv )+nho;
		nho=0;
		if(temp >9)
		{
			int x=temp%10;
			nho=temp/10;
			result= char(x+48) +result ;
		}	
		else
		{
			result= char(temp+48) +result;
		}	
	}
	if(nho!=0)
		result= char(nho+48) + result;
	return result;
}

