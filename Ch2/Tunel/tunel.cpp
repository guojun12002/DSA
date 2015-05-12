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
LL *hight, *maxhight;
int beg=0, ed=0, m=0;
int n;
LL x;
void in()
{
	scanf("%d", &x);
	hight[ed] = x;
	maxhight[ed] = x;
	m=ed-1;
	while(m>=beg && maxhight[m]<maxhight[ed])
		maxhight[m--]=maxhight[ed];
	++ed;
	return;
}
void out()
{
	printf("%lld\n", hight[beg++]);
	return;
}
void check()
{
	printf("%lld\n", maxhight[beg]);
	return;
}

int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	char c;
	scanf("%d\n",&n);
	hight= new LL[n];
	maxhight= new LL[n];
	while(scanf("%d", &c) != EOF)
	{
        scanf("%c",&c);
        switch(c)
        {
            case 'E':in();break;
            case 'D':out();break;
            default:check();
        }
	}
	return 0;
}
