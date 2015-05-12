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
const int MAX=10000001;
int code[MAX];
int sum=0,num=0;
bool worker[MAX];
bool isclosed=true;
int a,c;
int n,m;
int person[MAX];
int p=0;
void login()
{
	if(isclosed)
	{
	isclosed=false;
	for(int i=0;i<p;i++)
		worker[person[i]]=false;
	p=0;
	}
	scanf("%d%d",&a,&c);
	code[a]=c;
	if(!worker[a])
	{
		worker[a]=true;
		num++;
		person[p++]=a;
	}
}
void logout()
{
	scanf("%d",&a);
	if(worker[a] && !isclosed)
		num--;
	worker[a]=false;
}
void close()
{
	num=0;
	isclosed=true;
}
void number()
{
	sum+=num;
}
void query()
{
	scanf("%d",&a);
	if(worker[a] && !isclosed) sum+=code[a];
	else sum--;
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d%d",&n,&m);
	memset(worker, 0, n);
	char cmd;
	while(scanf("%c",&cmd)!=EOF)
		switch(cmd)
		{
			case 'I':login();break;
			case 'O':logout();break;
			case 'C':close();break;
			case 'N':number();break;
			case 'Q':query();break;
		}
	printf("%d\n", sum);
	return 0;
}