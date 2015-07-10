#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first<p2.first)
		return true;
	if(p1.first==p2.first && p1.second<p2.second)
		return true;
	return false;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	pair<int,int> points[n];
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&points[i].first,&points[i].second);
	}
	
	sort(points,points+n,comparator);
	
	for(int i=0;i<n;i++)
	{
		cout<<points[i].first<<"\t"<<points[i].second<<endl;
	}
	
	int dp[n];
	dp[0]=1;

	for(int i=1;i<n;i++)
	{
		if(points[i].first==points[i-1].first)
		{
			dp[i]=dp[i-1];
		}
		else if(points[i].second<=points[i-1].second)
		{
			int j=i-2;
			while(j>=0 && points[i].second<=points[j].second)
			{
				j--;
			}
			if(j==-1)
				dp[i]=1;
			else
				dp[i]=dp[j]+1;
		}
		else if(points[i].second>points[i-1].second)
		{
			dp[i]=dp[i-1]+1;
		}
	}


	int count=INT_MIN;
	
	for(int i=0;i<n;i++)
	{
		count=max(count,dp[i]);
	}
	
	printf("%d",count);
	
	return 0;
}
