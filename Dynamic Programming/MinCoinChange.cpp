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
    int dp[n][sum + 1];
    for (int i = 0; i < n; ++i)
        dp[i][0] = 0;
    for (int i = 1; i <= sum; ++i)
    {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = sum + 1;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            if (j - arr[i] >= 0)
                dp[i][j] = min(1 + dp[i][j - arr[i]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n - 1][sum];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    fast
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int ans = bottomUp(arr, n, sum);
    if (ans <= sum)
        cout << ans << endl;
    else
        cout << "Not Possible" << endl;
    return 0;
}