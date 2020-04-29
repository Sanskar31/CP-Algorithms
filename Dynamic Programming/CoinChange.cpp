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

void minCoin(int n, int coin[], int d)
{
    int dp[n+1], c[n+1];
    memset(dp, n+3, sizeof(dp));
    memset(c, -1, sizeof(c));
    dp[0]=0;
    for(int j=0;j<d;++j)
    {
        for(int i=1;i<=n;++i)
        {
            if(i-coin[j]<0)
                continue;
            else if(dp[i-coin[j]]==-1)
                continue;
            else if(dp[i]>1+dp[i-coin[j]])
            {
                c[i]=j;
                dp[i]=1+dp[i-coin[j]];
            }
        }
    }
    cout<<"Coins Required: "<<dp[n]<<endl;
    int i=n;
    cout<<"Coins Used Are: ";
    while(i!=0)
    {
        cout<<coin[c[i]]<<" ";
        i-=coin[c[i]];
    }
    cout<<endl;
}

int main()
{
    //fast
    int n, c;
    cin>>n>>c;
    int coin[c];
    for(int i=0;i<c;++i)
        cin>>coin[i];
    minCoin(n,coin, c);
    return 0;
}