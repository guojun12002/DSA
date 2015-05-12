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
const int MAX=500001;
int coach[3][MAX];
bool player[MAX];

int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	int n,k;
	while(scanf("%d",&n)!=EOF)
	{
		memset(player, 0, n);
		for(int i=0;i<3;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&coach[i][j]);
		scanf("%d",&k);
		int j[3]={};
		int i=0;
		while(n--)
		{
			while(player[coach[i][j[i]]]) j[i]++;
			player[coach[i][j[i]]]=true;
			if(coach[i][j[i]]==k) break;
			i=(i+1)%3;
		}
		switch(i)
		{
			case 0:printf("%c\n", 'A');break;
			case 1:printf("%c\n", 'B');break;
			default:printf("%c\n", 'C');break;
		}
	}
	return 0;
}