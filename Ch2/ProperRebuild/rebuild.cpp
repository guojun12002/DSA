#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int IO_BUF_SIZE=0x1000000;
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
int n;
int ps;
int* seq[2];
int* posh;
struct NODE
{
	int x;
	NODE *left,*right;
	NODE(int _x):x(_x),left(NULL),right(NULL){};
};
NODE* creat()
{
	return new NODE(seq[0][ps++]);
}

NODE* findchildren(NODE* father)
{
	if(ps==n) return NULL;
	int fpos=posh[father->x];
	int ppos=posh[seq[0][ps]];
	if(ppos-fpos < -1)
	{
		NODE* lc=creat();
		lc->left= findchildren(lc);
		lc->right= findchildren(lc);
		return lc;
	}
	else if(ppos-fpos < 0)
	{
		NODE* rc=creat();
		rc->left= findchildren(rc);
		rc->right= findchildren(rc);
		return rc;
	}
	else
		return NULL;
}
void print(NODE* p)
{
	if(p->left != NULL) print(p->left);
	printf("%d ", p->x);
	if(p->right != NULL) print(p->right);
}
int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d",&n);
	ps=0;
	seq[0]= new int[n];
	seq[1]= new int[n];
	posh= new int[n+1];
	for(int i=0;i<n;i++)
		scanf("%d",&seq[0][i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&seq[1][i]);
		posh[seq[1][i]]=i;
	}
	NODE* root= creat();
	root->left= findchildren(root);
	root->right= findchildren(root);
	print(root);
	return 0;
}