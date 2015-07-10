#include <bits/stdc++.h>
using namespace std;

typedef long long lld;

bool comparator(pair<lld,lld> p1,pair<lld,lld> p2)
{
    if(p1.first<p2.first)
        return true;
    if(p1.first==p2.first && p1.second<p2.second)
        return true;
    return false;
}

int main()
{
    lld n;
    scanf("%lld",&n);

    pair<lld,lld> points[n];

    for(lld i=0;i<n;i++)
    {
        scanf("%lld %lld",&points[i].first,&points[i].second);
    }

    sort(points,points+n,comparator);

    // for(int i=0;i<n;i++)
    //     cout<<points[i].first<<"\t"<<points[i].second<<endl;
    // cout<<endl;

    lld start=points[0].first;
    lld end=points[0].second;
    lld count=1;

    //cout<<start<<"\t"<<count<<endl;

    for(lld i=1;i<n;i++)
    {
        if(points[i].second <= end)
            continue;
        else if(points[i].first > start)
        {
            start=points[i].first;
            end=points[i].second;
            count++;
        }
        //cout<<start<<"\t"<<count<<endl;
    }

    printf("%lld",count);

    return 0;
}
