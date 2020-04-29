#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define max 1000000000

using namespace std;

void initialize(int dist[], int n)
{
    for(int i=0;i<=n;++i)
    {
        dist[i]= max;
    }
}

void algo(vector<pair<int, int>> *v, int dist[], int  n)
{
    int visited[n+1]={0};
    multiset<pair<int,int>> s;

    s.insert({0,1});

    while(!s.empty())
    {
        pair<int, int> p= *s.begin();
        s.erase(s.begin());

        int x= p.second, wei=p.first;

        if(visited[x])
            continue;

        visited[x]=1;

        for(int i=0;i<v[x].size();++i)
        {
            int e= v[x][i].first, w=v[x][i].second;
            if(dist[x]+w < dist[e])
            {
                dist[e]= dist[x] + w;
                s.insert({dist[e],e});
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int, int>> v[n+1];

    int dist[n+1];
    initialize(dist, n);
    dist[1]=0;

    for(int i=1;i<=m;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back(make_pair(b, w));
    }

    algo(v, dist, n);
    for(int i=2;i<=n;++i)
    {
        cout<<dist[i]<<" ";
    }
}