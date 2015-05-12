#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
int n;
int cost=0;
int t[15][15]={};
bool w[15]={};
void wl(int i,int c)
{
	if(i==n && c<cost)
	{
		cost= c;
		return;
	}
	if(c<cost)
		for(int j=0;j<n;j++)
			if(!w[j])
			{
				w[j]=true;
				wl(i+1,c+t[i][j]);
				w[j]=false;
			}
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>t[i][j];
			cost+=t[i][0];
		}
		wl(0,0);
		cout<<cost<<endl;
	}
	return 0;
}