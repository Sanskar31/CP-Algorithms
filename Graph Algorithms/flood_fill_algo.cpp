#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define max 1000000000

using namespace std;

bool dfs(int n, int m, vector<int> *mat, int x, int y, vector<bool> *visited)
{
    if(x>=n || y>=m)
        return false;
    if(x<0 || y<0)
        return false;
    if(x==n-1 && y==m-1)
        return true;
    if(visited[x][y])
        return false;
    if(mat[x][y]==0)
        return false;
    visited[x][y]=true;
    if(dfs(n,m,mat,x-1,y,visited))
        return true;
    if(dfs(n,m,mat,x,y-1,visited))
        return true;
    if(dfs(n,m,mat,x+1,y,visited))
        return true;
    if(dfs(n,m,mat,x,y+1,visited))
        return true;
    return false;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> mat[n];
    vector<bool> visited[m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            visited[i].push_back(false);
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int a;
            cin>>a;
            mat[i].push_back(a);
        }
    }
    if(dfs(n,m,mat,0,0,visited))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}