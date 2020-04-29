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

void initialize(bool visited[], int nodes)
{
    for (int i = 0; i <= nodes; ++i)
        visited[i] = false;
}

void dfs(int n, bool visited[], vector<int> *adj)
{
    if (visited[n])
        return;
    cout << n << " ";
    visited[n] = true;
    for (auto i : adj[n])
        dfs(i, visited, adj);
    return;
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
        adj[y].push_back(x);
    }
    int start = 1;
    bool visited[nodes + 1];
    initialize(visited, nodes);
    cout << "Order of Traversal is ";
    dfs(start, visited, adj);
    cout << endl;
    return 0;
}
