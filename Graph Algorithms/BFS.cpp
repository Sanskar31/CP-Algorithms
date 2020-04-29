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

void initialize(bool visited[], int nodes)
{
    for (int i = 0; i <= nodes; ++i)
        visited[i] = false;
}

void BFS(int s, bool visited[], vector<int> *v)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int p = q.front();
        cout << p << " ";
        q.pop();
        for (int i = 0 ; i < v[p].size(); ++i)
        {
            if (!visited[v[p][i]])
            {
                visited[v[p][i]] = true;
                q.push(v[p][i]);
            }

        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];
    for (int i = 0; i < edges; ++i)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool visited[nodes + 1];
    initialize(visited, nodes);
    cout << "Order Of Traversal is: ";
    BFS(1, visited, adj);
    cout << endl;
    return 0;
}

