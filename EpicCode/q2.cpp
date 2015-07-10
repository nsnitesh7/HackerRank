#include <bits/stdc++.h>
using namespace std;

int main()
{
	int len;
	long long int ch[26];
	
	for(int i=0;i<26;i++)
		ch[i]=0;
		
	scanf("%d\n",&len);
	
	char c;
	
	for(int i=0;i<len;i++)
	{
		scanf("%c",&c);
		ch[c-'a']++;
	}
	
	long long int ret=0;
	
	for(int i=0;i<26;i++)
	{
		ret+=(ch[i]*(ch[i]+1))/2;
		//cout<<(char)('a'+i)<<"\t"<<ch[i]<<"\t"<<ret<<endl;
	}
	
	printf("%lld",ret);
	
	return 0;
}
