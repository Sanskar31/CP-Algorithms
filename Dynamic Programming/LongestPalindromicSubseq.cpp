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

int longestPalindrome(string s)
{
    int n= s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    //Setting Diagonal Elements As 1
    for(int i=0,j=0;j<n,i<n;++i,++j)
        dp[i][j]=1;

    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<n-i+1;++j)
        {
            if(s[j]!=s[j+i-1])
                dp[j][j+i-1]= max(dp[j][j+i-2], dp[j+1][j+i-1]);
            else
                dp[j][j+i-1]= 2+dp[j+1][j+i-2];
        }
    }

    cout<<"OPTIMAL SUBSTRUCTURE:"<<endl;
    cout<<"\t";
    for(int i=0;i<n;++i)
        cout<<s[i]<<"\t";
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<s[i]<<"\t";
        for(int j=0;j<n;++j)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"Length Of Longest Palindromic Subsequence is: ";
    return dp[0][n-1];
}

int main()
{
    /*
        Longest Palindromic Subsequence
        string s= "AABCABB"
    */
    string s= "AABCABB";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}