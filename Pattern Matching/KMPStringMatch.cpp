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

vector<int> KMP(string text, string pattern)
{
	vector<int> ans;
	int n = text.size();
	int p = pattern.size();
	int res[p + 1];
	int j = -1, i = 0;
	res[0] = -1;
	while (i < p)
	{
		while (j >= 0 && pattern[j] != pattern[i])
			j = res[j];
		i++, j++;
		res[i] = j;
	}
	j = 0;
	i = 0;
	while (i < n)
	{
		while (j >= 0 && text[i] != pattern[j])
			j = res[j];
		i++, j++;
		if (j == p)
		{
			ans.push_back(i - j);
			j = res[j];
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
	getline(cin, text);
	getline(cin, pattern);
	vector<int> ans = KMP(text, pattern);
	cout << "Pattern found at index: ";
	for (auto i : ans)
		cout << i << " ";
	cout << endl;
	return 0;
}