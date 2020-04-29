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

//s= max weight, n= number of items
int s,n;

int bottomUp(vector<pair<int, int> > &v)
{
    int dp[n][s+1];
    for(int i=0;i<n;++i)
        dp[i][0]=0;
    for(int i=0;i<=s;++i)
    {
        if(v[0].first>i)
            dp[0][i]=0;
        else
            dp[0][i]=v[0].second;
    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=s;++j)
        {
            if(v[i].first>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                int wei= v[i].first;
                int val= v[i].second;
                dp[i][j]= max(val+dp[i-1][j-wei], dp[i-1][j]);
            }
        }
    }
    cout<<"OPTIMAL SUBSTRUCTURE:"<<endl;
    cout<<"WEIGHT:"<<"\t";
    for(int i=0;i<=s;++i)
        cout<<i<<"\t";
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<"ITEM:"<<i+1<<"\t";
        for(int j=0;j<=s;++j)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"MAX Value That Can Be Taken is ";
    return dp[n-1][s];
}

int main()
{
    fast
    /*
        Max Weight= 5
        Number Of Items= 4
        Item Value  Weight
        100         3
        20          2
        60          4
        40          1
    */
    //cin>>s>>n;
    s=5,n=4;
    vector< pair <int,int> > v;
    v.push_back({3,100});
    v.push_back({2,20});
    v.push_back({4,60});
    v.push_back({1,40});
    /*
    for(int i=0;i<n;++i)
    {
        int wei,val;
        cin>>wei>>val;
        v.push_back(make_pair(wei,val));
    }
    */
    cout<<bottomUp(v)<<endl;
}