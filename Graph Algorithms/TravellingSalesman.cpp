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

#define max_size 1 << 30;

int n = 4;
int dp[16][4];

int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
};

int VISITED_ALL = (1 << n) - 1;

int tsp(int mask, int pos)
{

    if (mask == VISITED_ALL)
    {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {
            int newAns = dist[pos][city] + tsp( mask | (1 << city), city);
            ans = min(ans, newAns);

        }
    }
    return dp[mask][pos] = ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << "Minimum Weight Hamiltonian Path Costs: " << tsp(1, 0) << endl;
    return 0;
}
