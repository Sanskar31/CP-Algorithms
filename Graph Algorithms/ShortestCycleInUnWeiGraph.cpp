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

vector<int> v[100005];
int par[100005], dist[100005];

int bfs(int nodes, int start)
{
	for (int i = 0; i <= nodes; ++i)
	{
		dist[i] = -1;
		par[i] = -1;
	}
	dist[start] = 0;
	par[start] = 0;
	queue<int> q;
	q.push(start);
	int shortest = nodes + 1;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (int i = 0; i < v[p].size(); ++i)
		{
			int d = v[p][i];
			if (par[d] != -1 && d != par[p])
				shortest = min(shortest, 1 + dist[d] + dist[p]);
			else if (d != par[p])
			{
				par[d] = p;
				dist[d] = dist[p] + 1;
				q.push(d);
			}
		}
	}
	return shortest;
}

void solve()
{
	int nodes, edges;
	cin >> nodes >> edges;

	for (int i = 0; i < edges; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int shortest = nodes + 1;
	for (int i = 1; i <= nodes; ++i)
		shortest = min(shortest, bfs(nodes, i));
	if (shortest == nodes + 1)
		shortest = 0;
	cout << shortest << endl;
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