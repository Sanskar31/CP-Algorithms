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

ll m, n;
const ll prime = 101;

bool compare(string text, string pattern, ll i, ll j)
{
	ll q = 0;
	for (ll k = i; k <= j; ++k)
	{
		if (text[k] != pattern[q])
			return false;
		q++;
	}
	return true;
}

ll findPow(ll num, ll p)
{
	ll ans = 1;
	for (ll i = 1; i <= p; ++i)
		ans *= num;
	return ans;
}

ll findHash(string s)
{
	ll hash = 0;
	ll p = 0;
	for (ll i = 0; i < m; ++i)
	{
		ll num = s[i];
		ll power = findPow(prime, p);
		hash += num * power;
		p++;
	}
	return hash;
}

vector<ll> rabinKarp(string text, string pattern)
{
	vector<ll> ans;
	n = text.length(), m = pattern.length();
	ll patternHash = findHash(pattern);
	ll textHash = findHash(text);
	for (ll i = 1; i <= n - m; ++i)
	{
		if (patternHash == textHash && compare(text, pattern, i - 1, i - 2 + m))
		{
			ans.push_back(i - 1);
		}
		if (i < n - m)
		{
			textHash -= text[i - 1];
			textHash /= prime;
			textHash += text[i + m - 1] * findPow(prime, m - 1);
		}
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	string text, pattern;
	cin >> text >> pattern;
	vector<ll> ans = rabinKarp(text, pattern);
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	return 0;
}