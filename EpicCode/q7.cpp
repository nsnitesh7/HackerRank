#include <bits/stdc++.h>
#define N 1000000009
using namespace std;

int main()
{
	long long int n,s,m;
	scanf("%lld %lld %lld",&n,&s,&m);
	
	long long int *a=new long long int[n];
	
	long long int sn;
	vector<long long int> si[s];
	long long int item;
	
	for(int i=0;i<s;i++)
	{
		scanf("%lld",&sn);
		for(int j=0;j<sn;j++)
		{
			scanf("%lld",&item);
			si[i].push_back(item);
		}
	}
	
	int code;
	long long int setID;
	long long int tValue;
	long long int l,r;
	
	for(int i=0;i<m;i++)
	{
		scanf("%d",&code);
		if(code==1)
		{
			scanf("%lld %lld",&setID,&tValue);
			int size=si[setID-1].size();
			for(int j=0;j<size;j++)
			{
				a[si[setID-1][j]-1]+=tValue;
			}
		}
		else if(code==2)
		{
			scanf("%lld",&setID);
			int size=si[setID-1].size();
			long long int sum=0;
			for(int j=0;j<size;j++)
			{
				sum+=a[si[setID-1][j]-1];
			}
			printf("%lld\n",sum%N);
		}
		else if(code==3)
		{
			scanf("%lld %lld %lld",&l,&r,&tValue);
			for(int j=l-1;j<r;j++)
			{
				a[j]+=tValue;
			}
		}
		else
		{
			scanf("%lld %lld",&l,&r);
			long long int sum=0;
			for(int j=l-1;j<r;j++)
			{
				sum+=a[j];
			}
			printf("%lld\n",sum%N);
		}
		/*
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<"  ";
		}
		cout<<endl;
		*/
	}
	
	return 0;
}
