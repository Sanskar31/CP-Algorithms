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

bool visited[200005], path[200005];

void initialize()
{
	memset(visited, false, sizeof(visited));
	memset(path, false, sizeof(path));
}

bool cycleCheck(int node, vector<int> *v)
{
	visited[node] = true;
	path[node] = true;

	for (auto child : v[node])
	{
		if (path[child])
			return true;
		else if (visited[child] == false)
		{
			bool check = cycleCheck(child, v);
			if (check)
				return true;
		}
	}
	path[node] = false;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y, nodes, edges;
	cin >> nodes;
	cin >> edges;
	vector <int> adj[nodes + 1];

	for (int i = 0; i < edges; ++i)
	{
		cin >> x >> y;
		adj[x].push_back(y);
	}
	initialize();
	bool check = cycleCheck(1, adj);
	if (check)
	{
		cout << "CYCLE is present!" << endl;
	}
	else
	{
		cout << "CYCLE is not present!" << endl;
	}
	return 0;
}