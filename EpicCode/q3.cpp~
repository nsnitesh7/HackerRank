#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k;
	scanf("%lld %lld",&n,&k);
	long long int a[n];
	long long int b[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&b[i]);
	}
	
	sort(a,a+n);
	sort(b,b+n);
	
	
	int i=0;
	int j=0;
	int pairs=0;
	
	while(i<n && j<n)
	{
		if(abs(a[i]-b[j])<=k)
		{
			pairs++;
			i++;
			j++;
		}
		else if(a[i]<b[j])
		{
			i++;
		}
		else if(a[i]>b[j])
		{
			j++;
		}
	}
	
	printf("%d",pairs);
	
	return 0;
}
