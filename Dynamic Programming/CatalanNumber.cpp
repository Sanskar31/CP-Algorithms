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

ll n, dp[10005];

ll topDown(ll node)
{
    if(node==0)
        return 1;
    if(dp[node]!=-1)
        return dp[node];
    dp[node]=0;
    for(ll i=1;i<=n;++i)
    {
        dp[node]+= topDown(node-i)*topDown(i-1);
    }
    return dp[node];
}

ll bottomUp()
{
    dp[0]=dp[1]=1;
    for(ll i=2;i<=n;++i)
    {
        dp[i]=0;
        for(ll j=1;j<=i;++j)
        {
            dp[i]+=dp[i-j]*dp[j-1];
        }
    }
    return dp[n];
}

int main()
{
    fast
    cin>>n;
    for(ll i=0;i<=n;++i)
        dp[i]=-1;
    dp[0]=1;
    cout<<topDown(n)<<endl;
    cout<<bottomUp()<<endl;
    return 0;
}