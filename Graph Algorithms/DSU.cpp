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

int id[100005];
int total = 0;
map<int, int> mp;

int root(int a)
{
	if (id[a] == a)
		return a;
	//Path Compression
	return id[a] = root(id[a]);
}

void uni(int a, int b)
{
	int r1 = root(a);
	int r2 = root(b);
	if (r1 != r2)
	{
		total--;
		id[r2] = r1;
		mp[r1] += mp[r2];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	// n-nodes q-query
	int n, q;
	cin >> n >> q;
	total = n;
	for (int i = 0; i <= n; ++i)
	{
		mp[i] = 1;
		id[i] = i;
	}
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
	cout << "Total Components: " << total << endl;
	cout << "Size Of Connected Components: " << endl;
	for (int i = 1; i <= n; ++i)
	{
		if (id[i] == i)
			cout << mp[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		int size_of_i = mp[root(i)];
		ans += n - size_of_i;
	}
	ans /= 2;
	cout << "Total Ways To choose two unconnected nodes: " << ans << endl;
	return 0;
}