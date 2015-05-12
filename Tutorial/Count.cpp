#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

int main()
{
	char str[4096];
	while(cin.getline(str, 4096))
	{
		int n[26]={};
		for(int i=0;i<strlen(str);i++)
		{
			if(str[i]>='A' && str[i]<='Z') n[str[i]-'A']++;
			else if(str[i]>='a' && str[i]<='z') n[str[i]-'a']++;
		}
		for(int i=0;i<26;i++)
			if(n[i]) printf("%c: %d\n", 'A'+i, n[i]);
	}
	return 0;
}