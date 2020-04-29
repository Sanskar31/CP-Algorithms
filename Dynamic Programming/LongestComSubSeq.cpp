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

int LCS(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    int dp[n1+1][n2+1];
    for(int i=0;i<=n1;++i) dp[i][0]=0;
    for(int i=0;i<=n2;++i) dp[0][i]=0;

    for(int i=1;i<=n1;++i)
    {
        for(int j=1;j<=n2;++j)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<"OPTIMAL SUBSTRUCTURE:"<<endl;
    cout<<"\t";
    cout<<"\'\\0\'\t";
    for(int i=0;i<=n2;++i)
        cout<<s2[i]<<"\t";
    cout<<endl;
    for(int i=0;i<=n1;++i)
    {
        if(i!=0)
            cout<<s1[i-1]<<"\t";
        else 
            cout<<"\'\\0\'\t";
        for(int j=0;j<=n2;++j)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"Length Of Longest Common Subsequence: ";
    return dp[n1][n2];
}

int main()
{
    /*
    string s1= AABCABB
    string s2= BCABABB
    */
    string s1, s2;
    s1="AABCABB" ,s2="BCABABB";
    //cin>>s1>>s2;
    cout<<LCS(s1, s2);
    return 0;
}