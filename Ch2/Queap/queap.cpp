#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const int IO_BUF_SIZE=0x100000;
const int MAX=1000001;
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

int n,x;
char c;
class Stack
{
public:
	Stack();
	bool empty();
	void push(int);
	int pop();
	int top();
	void print(); //debug
	~Stack();
private:
    int* data;
    int size;
};

void Stack::print() //debug
{
	printf("size=%d\n",size);
	for(int i=0;i<size;i++)
		cout<<data[i]<<' ';
	cout<<endl;
}
Stack::Stack()
{
	data= new int[n+5];
    size= 0;
}
Stack::~Stack()
{
	delete[] data;
}
bool Stack::empty()
{
    return size==0?true:false;
}

void Stack::push(int value)
{
    data[size++]=value;
}

int Stack::pop()
{
    return data[--size];
}

int Stack::top()
{
    return data[size-1];
}

class Queap
{
public:
	Queap();
	void enqueap(int);
	int dequeap();
	int min();
private:
    Stack s1,s2,smin1,smin2;
};

Queap::Queap()
{
	smin1.push(MAX);
}

void Queap::enqueap(int value)
{
	// s1.print();
	// smin1.print();
	if(s1.empty())
		while(!s2.empty())
			s1.push(s2.pop());
    s1.push(value);
    if(smin1.empty())
    	while(!smin2.empty())
    		smin1.push(smin2.pop());
    if(smin1.top() <= value)
    	smin1.push(value);
    else
    {
    	while(!smin1.empty() && smin1.top()>value)
    		smin1.pop();
    	smin1.push(value);
    }
}

int Queap::dequeap()
{
	while(!s1.empty())
		s2.push(s1.pop());
	while(!smin1.empty())
		smin2.push(smin1.pop());
	int m= s2.pop();
	if(m == smin2.top()) smin2.pop();
	// while(!s2.empty())
	// 	s1.push(s2.pop());
	// while(!smin2.empty())
	// 	smin1.push(smin2.pop());
	return m;
}

int Queap::min()
{
	while(!smin1.empty())
		smin2.push(smin1.pop());
	int m=smin2.top();
	// while(!smin2.empty())
	// 	smin1.push(smin2.pop());
	return m;
}
int main()
{
    #ifndef _OJ_
	freopen("input.txt", "r", stdin);
	#endif
	scanf("%d",&n);
	Queap qp;
	while(scanf("%c",&c) != EOF)
		switch(c)
		{
			case 'E':
				scanf("%d",&x);
				// printf("%c %d\n",c,x);
				qp.enqueap(x);
				break;
			case 'D':
				printf("%d\n", qp.dequeap());
				break;
			case 'M':
				printf("%d\n", qp.min());
				break;
		}
	return 0;
}
