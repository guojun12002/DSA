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
int n,m;
int* data;
int seq;
int* opration;
int *t;
int top()
{
	if(t==data) return 0;
	return *(t-1);
}
bool pop()
{
	if(t>data) t--;
	else return false;
	return true;
}
bool push(int no)
{
	if(t-data<m) *t++=no;
	else return false;
	return true;
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d%d",&n,&m);
	data=new int[n];
	opration=new int[n*2];
	t=data;
	int train=0,o=0,i;
	for(i=0;i<n;i++)
	{
		bool flag=true;
		scanf("%d",&seq);
		if(top() > seq) break;
		else
		{
			while(top()< seq)
				if(push(++train)) opration[o++]=0;
				else
				{
					flag= false;
					break;
				}
			if(!flag) break;
			if(top()==seq)
			{
				pop();
				opration[o++]=1;
			}
		}
	}
	if(i<n)
		printf("No\n");
	else
		printf("Yes\n");
		// for(int j=0;j<n*2;j++)
		// 	if(opration[j]==0) printf("push\n");
		// 	else printf("pop\n");
	return 0;
}