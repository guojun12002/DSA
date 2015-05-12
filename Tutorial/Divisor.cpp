#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
	if(a%b!=0) return gcd(b,a%b);
	else return b;
}
int main()
{
	LL a,b;
	while(cin>>a>>b)
	{
		if(a<b)
		{
			LL c=a^b;
			a=a^c;
			b=a^c;
		}
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}