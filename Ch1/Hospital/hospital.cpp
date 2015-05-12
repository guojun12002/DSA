#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
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
const int MAX=40000;
LL vilidge[MAX]={};

int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	int n;
	scanf("%d",&n);
	int x;
	LL w;
	int max=-1,min=MAX;
	for(int i=0;i<n;i++)
	{
		scanf("%d%lld",&x,&w);
		vilidge[x]+= w;
		if(max < x) max = x;
		if(x < min) min = x;
	}
	int i=min,j=max;
	LL suml=vilidge[i],sumr=vilidge[j];
	while(i<j)
		if(suml < sumr)
			suml += vilidge[++i];
		else
			sumr += vilidge[--j];
	int best= suml<sumr? j:i;
	LL sum=0;
	for(i=min;i<=max;i++)
		sum+= abs(i-best)*vilidge[i];
	printf("%d\n%lld\n", best, sum);

	return 0;
}