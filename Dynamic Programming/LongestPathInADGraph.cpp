/*
Author: Sanskar Agarwal
Nick: sanskarag
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
#define test while(t--)solve();

void solve()
{
	string S, T;
	cin >> S >> T;
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
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	fast
	ll t;
	// cin >> t;
	t = 1;
	test
	return 0;
}