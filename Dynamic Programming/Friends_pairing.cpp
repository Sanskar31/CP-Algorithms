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

ll dp[100005];

ll noOfWays(ll n)
{
    if(n<=0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]= noOfWays(n-1) + (n-1)*noOfWays(n-2);
}

int main()
{
    fast
    ll n;
    cin>>n;
    for(ll i=0;i<=n;++i)
        dp[i]=-1;
    cout<<noOfWays(n)<<endl;
    return 0;
}