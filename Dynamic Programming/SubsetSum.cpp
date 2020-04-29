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
#define F(i,a,b) for(string i = (string)(a); i <= (string)(b); i++)
#define RF(i,a,b) for(string i = (string)(a); i >= (string)(b); i--)
#define INF 100009
#define mod 1000000007
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second

int bottomUp(int arr[], int n, int sum)
{
    bool dp[n][sum+1];
    for(int i=0;i<n;++i)
        dp[i][0]=true;
    for(int i=1;i<=sum;++i)
        dp[0][i]=false;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=sum;++j)
        {
            if(arr[i]>j || dp[i-1][j]==true)
                dp[i][j]= dp[i-1][j];
            else
            {
                if(dp[i-1][j-arr[i]]==true)
                    dp[i][j]=true;
                else 
                    dp[i][j]=false;
            }
        }
    }
    return dp[n-1][sum];
}

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;++i)
        cin>>arr[i];
    bool ans= bottomUp(arr, n, sum);
    if(ans)
         cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
    return 0;
}