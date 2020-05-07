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

vector<int> adj[100005], art;
vector<pair<int, int> > bridge;
int disc[100005], low[100005], tme = 0;

void dfs(int curr, int par)
{
	disc[curr] = low[curr] = tme++;
	int no_of_child = 0;
	for (auto child : adj[curr])
	{
		if (disc[child] < 0)
		{
			no_of_child++;
			dfs(child, curr);
			low[curr] = min( low[curr] , low[child]);

			// Articulation Point
			if (par != 0 && low[child] >= disc[curr])
				art.push_back(curr);
			//Bridge Edge
			if (low[child] < disc[curr])
				bridge.push_back({curr, child});
		}
		else if (child != par)
		{
			//Backedge Or Cycle Found
			low[curr] = min(low[curr], disc[child]);
		}
	}
	// When Root Node Is Articulation Point
	if (par == 0 && no_of_child > 1)
		art.push_back(curr);
	return;
}

void solve()
{
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i <= nodes; ++i)
	{
		disc[i] = -1;
		low[i] = -1;
	}
	for (int i = 0; i < edges; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);

	cout << "Articulation Points Are: ";
	for (auto i : art)
		cout << i << " ";
	cout << endl;
	cout << "Bridge Edges are:" << endl;
	for (auto i : bridge)
		cout << i.first << " ---> " << i.second << endl;
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