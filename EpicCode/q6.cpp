#include <bits/stdc++.h>
#define N 1000000007
using namespace std;

int main()
{
	long long int n,q;
	scanf("%lld %lld",&n,&q);
	
	long long int *a=new long long int[n];
	
	long long int code,x,y;
	
	for(int i=0;i<q;i++)
	{
		scanf("%lld %lld %lld",&code,&x,&y);
	
		if(code==1)
		{
			long long int multiple=1;
		
			for(int j=x-1;j<y;j++)
			{
				a[j]+=multiple*(multiple+1);
				multiple++;
			}
		}
		else
		{
			long long int sum=0;
			for(int j=x-1;j<y;j++)
			{
				sum+=a[j];
			}
			printf("%lld\n",sum%N);
		}
	}
	
	
	
	return 0;
}
