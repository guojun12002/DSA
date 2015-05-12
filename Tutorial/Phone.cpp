#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;

int main()
{
	string str1,str2;
	while(cin>>str1>>str2)
	{
		int t=0;
		for(int i=0;i<3;i++)
		{
			int t1=0,t2=0;
			for(int j=0;j<2;j++)
			{
				t1=t1*10+(str1[i*3+j]-'0');
				t2=t2*10+(str2[i*3+j]-'0');
			}
			if(i==0) t+=((t2+24-t1)%24)*3600;
			if(i==1) t+=(t2-t1)*60;
			if(i==2) t+=t2-t1;
		}
		cout<<t<<endl;
	}
	return 0;
}