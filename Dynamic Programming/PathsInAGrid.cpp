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
#define test while(t--)solve();

int dp[1005][1005];
string s[1005];
int h, w;

int countPaths(int x, int y)
{
	if (x > h || y > w)
		return 0;
	if (s[x - 1][y - 1] == '#')
		return dp[x][y] = 0;
	if (x == h && y == w)
		return dp[x][y] = 1;
	if (dp[x][y] != -1)
		return dp[x][y];
	return dp[x][y] = (countPaths(x + 1, y) % mod + countPaths(x, y + 1) % mod) % mod;
}

void solve()
{
	cin >> h >> w;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < h; ++i)
		cin >> s[i];
	cout << countPaths(1, 1) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	/*
		Problem Statement-- https://atcoder.jp/contests/dp/tasks/dp_h
	*/
	fast
	int t;
	// cin >> t;
	t = 1;
	test
	return 0;
}