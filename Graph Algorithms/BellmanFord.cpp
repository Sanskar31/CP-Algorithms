/*
Author: Sanskar Agarwal
Nick: sanskaragarwal
Birla Institute Of Technology, Mesra
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
#define INF 100009
#define mod 1000000007
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second

void bellmanFord(vector<ll> *v, ll n, ll m, ll s)
{
    ll dist[n+1];
    for(int i=0;i<n+1;++i)
        dist[i]=INT_MAX;
    dist[s]=0;
    for(ll j=0;j<n-1;++j)
    {
        for(ll i=0;i<m; ++i)
        {
            ll a= v[i][0];
            ll b= v[i][1];
            ll wei= v[i][2];
            if(dist[a]+wei<dist[b])
                dist[b]=dist[a]+wei;
        }
    }
    for(ll i=0;i<m; ++i)
    {
        ll a= v[i][0];
        ll b= v[i][1];
        ll wei= v[i][2];
        if(dist[a]+wei<dist[b])
        {
            cout<<"There is a negative weighted edge cycle in graph!"<<endl;
            return;
        }
    }
    for(ll i=1;i<=n;++i)
    {
        cout<<s<<" --> "<<i<<" --> "<<dist[i]<<endl;
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> v[m];
    for(ll i=0;i<m;++i)
    {
        ll a,b,wei;
        cin>>a>>b>>wei;
        v[i].push_back(a);
        v[i].push_back(b);
        v[i].push_back(wei);
    }
    ll s;
    cin>>s;
    bellmanFord(v,n,m,s);
    return 0;
}