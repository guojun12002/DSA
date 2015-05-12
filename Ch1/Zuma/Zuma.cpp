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

struct node
{
	char c;
	node *pre,*next;
};
node* creat(char c)
{
	node* p=(node*)malloc(sizeof(node));
	if(p!=NULL)
	{
		p->c=c;
		p->pre=NULL;
		p->next=NULL;
	}
	return p;
}
node* insert(node* p,char c)
{
	node* q=creat(c);
	q->next=p->next;
	if(q->next!=NULL) q->next->pre=q;
	q->pre=p;
	p->next=q;
	return q;
}
node* del(node* p)
{
	node* q=p->next;
	if(p->next != NULL)
		p->next->pre=p->pre;
	if(p->pre !=NULL)
		p->pre->next=p->next;
	free(p);
	return q;
}
node* init(char *str)
{
	int len=strlen(str);
	if(len<1) return NULL;
	node* head=creat(str[0]);
	node* p=head;
	for(int i=1;i<len;i++)
		p=insert(p,str[i]);
	return head;
}
void print(node* p)
{
	if(p == NULL)
	{
		printf("-\n");
		return;
	}
	while(p!=NULL)
	{
		printf("%c",p->c);
		p=p->next;
	}
	printf("\n");
}
node* check(node* head,node* p,bool flag)
{
	if(p==NULL) return head;
	int sumpre=0,sumnext=0,sum;
	node* pre=p->pre;
	node* next=p->next;
	node* beg=p;
	while(pre!=NULL && pre->c == p->c)
	{
		++sumpre;
		beg=beg->pre;
		pre=pre->pre;
	}
	while(next!=NULL && next->c == p->c)
	{
		++sumnext;
		next=next->next;
	}
	if(flag) sum=sumpre+sumnext;
	else sum= sumpre>0? (sumpre+sumnext):0;
	if(sum>=2)
	{
		if(pre!=NULL) pre->next=next;
		if(next!=NULL) next->pre=pre;
		if(beg==head) head=next;
		while(beg != next) beg=del(beg);
		if(next!=NULL) head=check(head, next, false);
	}
	return head;
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	char str[20000];
	int n;
	gets(str);
	scanf("%d",&n);
	node* head=init(str);
	int k;
	char c;
	for(int i=0;i<n;i++)
	{
		node* p=head;
		scanf("%d %c",&k,&c);
		if(k==0)
		{
			p=creat(c);
			p->next=head;
			if(head != NULL) head->pre=p;
			head=p;
		}
		else
		{
			while(--k>0)
				p=p->next;
			p=insert(p, c);
		}
		head=check(head,p,true);
		print(head);
	}
	return 0;
}