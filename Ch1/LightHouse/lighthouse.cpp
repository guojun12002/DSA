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

int lightx[4000000], lighty[4000000];
LL sum=0;
void swap(int* p,int *q)
{
	int tmp=*p;
	*p=*q;
	*q=tmp;
}
int partition(int l, int r)
{
	int i=l-1,j=r;
	int v=lightx[r];
	for(;;)
	{
		while(lightx[++i]<v);
		while(v<lightx[--j]) if(j==l) break;
		if(i>=j) break;
		swap(lightx+i,lightx+j);
		swap(lighty+i,lighty+j);
	}
	swap(lightx+i,lightx+r);
	swap(lighty+i,lighty+r);
	return i;
}
void quicksort(int l, int r)
{
	int i;
	if(l>=r) return;
	i=partition(l,r);
	quicksort(l,i-1);
	quicksort(i+1,r);
}
void merge(int l,int m,int r)
{
	LL i,j,k;
	for(i=m+1;i>l;i--) lightx[i-1]=lighty[i-1];
	for(j=m;j<r;j++) lightx[r+m-j]=lighty[j+1];
	for(k=l;k<=r;k++)
		if(lightx[i]<lightx[j])
		{
			lighty[k]=lightx[i++];
			sum+=j-m;
		}
		else
			lighty[k]=lightx[j--];
}
void mergesort(int l,int r)
{
	int m=(r+l)/2;
	if(r<=l) return;
	mergesort(l,m);
	mergesort(m+1,r);
	merge(l,m,r);
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&lightx[i],&lighty[i]);
	quicksort(0, n-1);
	mergesort(0, n-1);
	cout<<sum<<endl;
	return 0;
}