#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long a,b;
	char c;
	while(cin>>a>>c>>b)
		switch(c)
		{
			case '+':cout<<a+b<<endl;break;
			case '-':cout<<a-b<<endl;break;
			case '*':cout<<a*b<<endl;break;
		}
	return 0;
}