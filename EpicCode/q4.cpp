#include <bits/stdc++.h>
#define N 3500
using namespace std;

long long int maximum=INT_MIN;

long long int dp[N][N];

long long int calculate(long long int *a, int i, int j,long long int compare)
{
	if(dp[i][j]!=INT_MIN)
		return dp[i][j];
	if(i<j)
	{
		compare=compare+a[i]*a[j];
		maximum=max(maximum,compare);
		dp[i][j]=a[i]*a[j]+calculate(a,i+1,j-1,compare);
		return dp[i][j];
	}
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	

	long long int a[n];

	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=INT_MIN;
		}
	}

	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dp[i][j]=calculate(a,i,j,0);
			maximum=max(maximum,dp[i][j]);
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}

	printf("%lld",maximum);
		
	return 0;
}
