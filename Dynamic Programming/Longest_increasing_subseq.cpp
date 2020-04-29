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

int n, arr[100005], dp[100005];

// O(n^2)
int LIS()
{
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(arr[i]>arr[j])
                dp[i]=max(dp[i], dp[j]+1);
        }
    }
    int maxc=1;
    for(int i=0;i<n;++i)
        maxc=max(maxc,dp[i]);
    return maxc;
}

// O(nlogn)
int optimizedLIS()
{
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1;i<n;++i)
    {
        if(arr[i]>*v.rbegin())
            v.push_back(arr[i]);
        else
        {
            auto itr= lower_bound(v.begin(), v.end(), arr[i]);
            *itr= arr[i];
        }
    }
    return v.size();
}

int main()
{
    fast
    cin>>n;
    for(int i=0;i<n;++i)
    {
        dp[i]=1;
        cin>>arr[i];
    }
    cout<<LIS()<<endl;
    cout<<optimizedLIS()<<endl;
    return 0;
}