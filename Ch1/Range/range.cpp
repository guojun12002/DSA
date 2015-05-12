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
const int MAX=1000000;
int num[MAX];
int numb[MAX];
void merge(int l,int m,int r)
{
	int i,j,k;
	for(i=m+1;i>l;i--) numb[i-1]=num[i-1];
	for(j=m;j<r;j++) numb[r+m-j]=num[j+1];
	for(k=l;k<=r;k++)
		if(numb[i]<numb[j]) num[k]=numb[i++];
		else num[k]=numb[j--];
}
void mergesort(int l,int r)
{
	int m=(r+l)/2;
	if(r<=l) return;
	mergesort(l,m);
	mergesort(m+1,r);
	merge(l,m,r);
}
int search(double x,int n)
{
	int l=0,r=n;
	while(l<r)
	{
		int m=(l+r)/2;
		if(x==num[m]) return m;
		else if(x<num[m]) r=m;
		else l=m+1;
	}
	return l;
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt","r",stdin);
	#endif
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int a,b;
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		mergesort(0,n-1);
		for(int mm=0;mm<m;mm++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",search(b+0.5,n)-search(a-0.5, n));
		}
	}
	return 0;
}