#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,p;
    int x;
    scanf("%lld %lld %d",&n,&p,&x);
    
    long long int maximum=INT_MIN;
    long long int val;
    int id=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&val);
        if(p*val>maximum)
        {
            maximum=p*val;
            id=i+1;
        }
        p=p-x;
    }
    printf("%d",id);
    return 0;
}
