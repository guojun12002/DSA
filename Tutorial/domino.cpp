#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
int n;
class domino
{
	char data[4001];
public:
	domino(){data[0]='\0';}
	domino(domino& d){strcpy(data, d.data);}
	domino& operator=(domino& d){strcpy(data, d.data);}
	domino& operator+(domino& d)
	{
		for(int i=0;i<4000;i++)
		{
			int c=0;
		}
	}
	~domino();
};
int main()
{
	while(cin>>n)
	{

	}
	return 0;
}