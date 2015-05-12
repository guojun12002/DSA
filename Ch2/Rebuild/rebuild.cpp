#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int IO_BUF_SIZE=0x100000;
const int MAX=500005;
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
int pre[MAX],mid[MAX],hp[MAX],s[MAX];
int si;
bool flag;
// struct Node
// {
// 	int ml,mr,root;
// 	Node(){};
// 	Node(int _ml,int _mr,int _root):ml(_ml),mr(_mr),root(_root){};
// 	Node& operator=(Node& N)
// 	{
// 		ml=N.ml;
// 		mr=N.mr;
// 		root=N.root;
// 	}
// }S[MAX];
// int Si;
// bool empty()
// {
// 	return Si==0?true:false;
// }
// void push(Node N)
// {
// 	S[Si++]=N;
// }
// Node pop()
// {
// 	return S[--Si];
// }
// Node top()
// {
// 	return S[Si-1];
// }
void findchild(int ml, int mr, int root)
{
	if(ml>=mr || root>=n) return;
	if(ml+1 != mr)
	{
		int pm=hp[pre[root]];
		int m=pm-ml;
		if(pm<ml || pm>mr)
		{
			flag=false;
			return;
		}
		findchild(ml, pm, root+1);
		findchild(pm+1, mr, root+1+m);
	}
	if(ml+1==mr && pre[root] != mid[ml])
	{
		flag=false;
		return;
	}
	s[si++]=pre[root];
	return;
}

int main()
{
	#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	#endif
	while(scanf("%d",&n) != EOF)
	{
		si=0;
		flag=true;
		//Si=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pre[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&mid[i]);
			hp[mid[i]]=i;
		}
		findchild(0, n, 0);

		// push(Node(0,n,0));
		// while(!empty())
		// {
		// 	Node R=pop();
		// 	int ml=R.ml,mr=R.mr,root=R.root;
		// 	if(ml>=mr || root>=n) continue;
		// 	if(ml+1 != mr)
		// 	{
		// 		int pm=hp[pre[root]];
		// 		int m=pm-ml;
		// 		if(pm>mr || pm<ml)
		// 		{
		// 			flag=false;
		// 			break;
		// 		}
		// 		push(Node(ml,pm,root+1));
		// 		push(Node(pm+1,mr,root+1+m));
		// 	}
			// if(ml+1==mr && pre[root] != mid[ml])
			// {
			// 	flag=false;
			// 	break;
			// }
		// 	s[si++]= pre[root];
		// }
		if(flag)
		{
			// while(--si>=0)
			for(int i=0;i<si;i++)
				printf("%d ", s[i]);
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}