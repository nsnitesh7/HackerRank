#include <bits/stdc++.h>
#define N 10009
using namespace std;

struct node
{
	vector<node *> childs;
	long long int value;
	node *parent;
};

long long int findsum(node *p)
{
	if(p==NULL)
		return 0;
	int size=p->childs.size();
	long long int sum=0;
	sum=p->value;
	for(int i=0;i<size;i++)
	{
		sum+=findsum(p->childs[i]);
	}
	return sum;
}

void incrementSum(node *p,int tValue)
{
	if(p!=NULL)
	{
		p->value+=tValue;
		int size=p->childs.size();
		for(int i=0;i<size;i++)
		{
			incrementSum(p->childs[i],tValue);
		}
	}
}

vector<node *> LoopNodes(node *p, node *q)
{
	vector<node *> temp1;
	vector<node *> temp2;
	
	node *pStore=p;
	node *qStore=q;
	
	while(p!=NULL)
	{
		temp1.push_back(p);
		if(p==q)
		{
			return temp1;
		}
		p=p->parent;
	}
	
	p=pStore;
	
	while(q!=NULL)
	{
		temp2.push_back(q);
		if(p==q)
		{
			return temp2;
		}
		q=q->parent;
	}
	
	stack<node *> p1;
	stack<node *> q1;
	vector<node *> visited;
	
	p=pStore;
	q=qStore;
	
	while(p!=NULL)
	{
		p1.push(p);
		visited.push_back(p);
		p=p->parent;
	}
	
	while(q!=NULL)
	{
		if(find(visited.begin(),visited.end(),q)!=visited.end())
		{
			while(!p1.empty() && p1.top()!=q)
			{
				visited.erase(find(visited.begin(),visited.end(),p1.top()));
				p1.pop();
			}
			return visited;
		}
		else
		{
			visited.push_back(q);
			q=q->parent;
		}
	}
	vector<node *> x;
	return x;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	node *nodes[n];
	
	for(int i=0;i<n;i++)
	{
		nodes[i]=new node;
		nodes[i]->value=0;
	}
	
	int from,to;
	nodes[0]->parent=NULL;
	
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d",&from,&to);
		nodes[from-1]->childs.push_back(nodes[to-1]);
		nodes[to-1]->parent=nodes[from-1];
	}
	
	int m;
	scanf("%d",&m);
	
	int code,a,b,tValue;
	
	for(int i=0;i<m;i++)
	{
		scanf("%d",&code);
		if(code==1)
		{
			scanf("%d %d %d",&a,&b,&tValue);
			vector<node *> loopnodes = LoopNodes(nodes[a-1],nodes[b-1]);
			
			for(int k=0;k<loopnodes.size();k++)
				incrementSum(loopnodes[k],tValue);
			/*
			for(int k=0;k<loopnodes.size();k++)
				printf("%lld\n",loopnodes[k]->value);
			*/
		}
		else
		{
			scanf("%d",&a);
			printf("%lld\n",findsum(nodes[a-1])%N);
		}
	}
	
	return 0;
}
