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
struct IV
{
	int no;
	IV *next,*pre;
	IV(int n):no(n),next(NULL),pre(NULL){};
};
IV* init(int no)
{
	IV* head=new IV(no);
	head->next=head;
	head->pre=head;
	return head;
}
IV* insert(IV* pre,int no)
{
	for(int i=0;i<m-1;i++)
		pre=pre->next;
	IV* next=pre->next;
	IV* mid=new IV(no);
	pre->next=mid;
	mid->pre=pre;
	mid->next=next;
	next->pre=mid;
	return mid;
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d%d",&n,&m);
	int id;
	scanf("%d",&id);
	IV* head=init(id);
	IV* next=head;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&id);
		next=insert(next,id);
	}
	printf("%d ",next->no);
	IV* pre=next->pre;
	while(pre!=next)
	{
		printf("%d ", pre->no);
		pre=pre->pre;
	}
	return 0;
}