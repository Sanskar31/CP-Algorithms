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

ll n,k,dp[100005];

ll countWays(ll n)
{
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    ll ways=0;
    for(ll i=1;i<=k;++i)
    {
        if(n-i>=0)
        {
            ways+= countWays(n-i);
        }
        else 
            break;
    }
    return ways;
}

ll bottomUp()
{
    dp[0]=1, dp[1]=1;
    for(ll i=2;i<=k;++i)
        dp[i]=2*dp[i-1];
    for(ll i=k+1;i<=n;++i)
    {
        dp[i]=2*dp[i-1]-dp[i-k-1];
            continue;
    }
    return dp[n];
}

int main()
{
    fast
    cin>>n>>k;
    for(ll i=0;i<=n;++i)
        dp[i]=-1;
    dp[0]=1;
    cout<<countWays(n)<<endl;
    cout<<bottomUp()<<endl;
    return 0;
}