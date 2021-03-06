#include<bits/stdc++.h>
#define N 1000000007
using namespace std;
    // #define PR(x) cout << #x " = " << x << "\n";
 
int64_t arr[100006];
int64_t t[262200];
int64_t lazy[262200];
 
void build(int64_t node, int64_t a, int64_t b)
{
	if(a>b) return;
	if (a==b)
	{
		t[node]=arr[a];
		return;
	}
	
	build(node*2, a, (a+b)/2);
	build(node*2+1,(a+b)/2+1,b);
	
	t[node]=t[node*2]+t[node*2+1];
}
 
int64_t query(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j)
{
	if(a>b||a>j||b<i) return 0;
	if (lazy[node] !=0 )
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if (a>=i && b<=j) return t[node];
	
	int64_t q1=query(node*2, a, (a+b)/2, i, j);
	int64_t q2=query(node*2+1, (a+b)/2+1, b, i, j);
	
	return q1+q2;
}
 
void update(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j, int64_t inc)
{
	if(a>b) return;
	if (lazy[node]!=0)
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b||a>j||b<i) return;
	
	if (a>=i && b<=j)
	{
		t[node]+=inc*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=inc;
			lazy[node*2+1]+=inc;
		}
		return;
	}
	
	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = t[node*2] + t[node*2+1];
}
 
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	
	memset(lazy, 0, sizeof lazy);
	
	for(int i = 0; i < n; i++)
		arr[i] =0;

	long long int code,x,y;
	
	build(1, 0, n-1);
	
	for(int i=0;i<q;i++)
	{
		scanf("%lld %lld %lld",&code,&x,&y);
	
		if(code==1)
		{
			update(1, 0, n-1, x-1, y-1, 1);
			//exit(1);
		}
		else
		{
			printf("%lld\n",query(1, 0, n-1, x-1, y-1)%N);
		}
	}
}
