#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const int MAX= 1e5+5;
int edges, nodes, id[MAX];
pair<ll, pair<int, int> > p[MAX];

void initialze()
{
    for(int i=0;i<MAX;++i)
        id[i]=i;
}

int root(int i)
{
    if(id[i]==i)
        return i;
    return root(id[i]);
}

void union1(int q1, int q2)
{
    int r1= root(q1);
    int r2= root(q2);
    id[r1]=id[r2];
}

int kruskal()
{
    int minimumCost=0, cost;
    for(int i=0;i<edges;++i)
    {
        int x= p[i].second.first;
        int y= p[i].second.second;
        int cost= p[i].first;
        if(root(x)!=root(y))
        {
            minimumCost+=cost;
            union1(x,y);
        }
    }
    return minimumCost;
}

int main()
{
    fast
    initialze();
    cin>>nodes>>edges;
    for(int i=0;i<edges;++i)
    {
        int a,b,wei;
        cin>>a>>b>>wei;
        p[i]= make_pair(wei,make_pair(a,b));
    }
    sort(p, p+edges);
    cout<<kruskal()<<endl;
    return 0;
}