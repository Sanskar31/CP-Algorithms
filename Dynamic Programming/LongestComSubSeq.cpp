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

void LCS(string S, string T)
{
    int s = S.length();
    int t = T.length();
    int dp[s + 1][t + 1];
    for (int i = 0; i <= s; ++i)dp[i][0] = 0;
    for (int i = 0; i <= t; ++i)dp[0][i] = 0;
    for (int i = 1; i <= s; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            if (S[i - 1] == T[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout<<"Length Of LCS: "<<dp[s][t]<<endl<<"LCS is: ";
    int i = s, j = t;
    stack<char> st;
    while (st.size() != dp[s][t])
    {
        if (S[i - 1] == T[j - 1])
        {
            st.push(S[i - 1]);
            i--, j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    if (st.empty())
        cout << "" << endl;
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    /*
    string s1= AABCABB
    string s2= BCABABB
    */
    string s1, s2;
    s1 = "AABCABB" , s2 = "BCABABB";
    //cin>>s1>>s2;
    LCS(s1, s2);
    return 0;
}