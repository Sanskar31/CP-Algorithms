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

int editDist(string a, string b)
{
    int n1=b.length();
    int n2=a.length();
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;++i)
        dp[i][0]=i;
    for(int i=0;i<=n2;++i)
        dp[0][i]=i;
    
    for(int i=1;i<=n1;++i)
    {
        for(int j=1;j<=n2;++j)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            else 
                dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                
        }
    }
    return dp[n1][n2];
}

int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        cout<<editDist(a,b)<<endl;
    }
    return 0;
}