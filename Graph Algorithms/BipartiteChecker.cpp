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

vector<int> adj[100005], comp[2];
bool odd_cycle = false;
int visited[100005];

void dfs(int curr, int par, int col)
{
	visited[curr] = col;
	comp[col - 1].push_back(curr);
	int child_col = (col == 1 ? 2 : 1);
	for (auto child : adj[curr])
	{
		if (visited[child] == 0)
			dfs(child, curr, child_col);
		else if (child != par && col == visited[child])
			odd_cycle = true;
	}
	return;
}

void solve()
{
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i <= nodes; ++i)
		visited[i] = 0;
	for (int i = 0; i < edges; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 1);

	if (odd_cycle)
		cout << "Graph Is Not Bipartite!" << endl;
	else
	{
		cout << "Graph Is Bipartite!" << endl;
		cout << "Colour 1: ";
		for (auto i : comp[0])
			cout << i << " ";
		cout << endl;
		cout << "Colour 2: ";
		for (auto i : comp[1])
			cout << i << " ";
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fast
	int t;
	t = 1;
	// cin >> t;
	test;
	return 0;
}