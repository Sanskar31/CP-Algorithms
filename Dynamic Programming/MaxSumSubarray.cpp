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

int maxSum(int arr[], int n)
{
    int dp[n]={0};
    dp[0]= (arr[0]>0)?arr[0]:0;
    int max_so_far=dp[0];
    for(int i=1;i<n;++i)
    {
        dp[i]=dp[i-1]+arr[i];
        if(dp[i]<0)
            dp[i]=0;
        max_so_far= max(max_so_far, dp[i]);
    }
    return max_so_far;
}

int maxSumSpaceOpt(int arr[], int n)
{
    int max_inc_this= (arr[0]>0)?arr[0]:0;
    int max_so_far= max_inc_this;
    for(int i=1;i<n;++i)
    {
        max_inc_this+= arr[i];
        max_inc_this= max(0, max_inc_this);
        max_so_far= max(max_inc_this, max_so_far);
    }
    return max_so_far;
}

int main()
{
    fast
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    cout<<maxSum(arr, n)<<endl;
    cout<<maxSumSpaceOpt(arr, n)<<endl;
    return 0;
}