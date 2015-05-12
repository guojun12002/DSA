#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int IO_BUF_SIZE=0x100000;
struct fastio
{
	char inbuf[IO_BUF_SIZE];
	char outbuf[IO_BUF_SIZE];
	fastio()
	{
		setvbuf(stdin, inbuf, _IOFBF, IO_BUF_SIZE);
		setvbuf(stdout, outbuf, _IOFBF, IO_BUF_SIZE);
	}
}io;
const int MAX=100005;
LL v[2][MAX];
int n,m;
int a,b;
struct vector
{
	LL x,y;
	vector(){};
	vector(LL xx,LL yy):x(xx),y(yy){};
	vector& operator=(vector& p)
	{
		x=p.x;
		y=p.y;
		return *this;
	}
	friend LL operator*(vector, vector);
	void print()
	{
		cout<<x<<' '<<y<<endl;
	}
};
LL operator*(vector p1, vector p2)
{
	return p1.x*p2.y-p1.y*p2.x;
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%lld %lld",&v[0][i], &v[1][i]);
	for(int i=0;i<m;i++)
	{
		scanf("%lld %lld",&a, &b);
		int l=0,r=n;
		while(l<r)
		{
			int m=(l+r)>>1;
			vector P(a,b-v[1][m]);
			vector Q(v[0][m],-v[1][m]);
			LL p=P*Q;
			if(p>0) r=m;
			else l=m+1;
		}
		printf("%d\n", l);
	}
	return 0;
}