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

int cutRod(int n, int price[])
{
    int val[n+1];
    val[0]=0;
    for(int i=1;i<=n;++i)
    {
        int max_value= INT_MIN;
        for(int j=0;j<i;++j)
            max_value= max(max_value, price[j]+val[i-j-1]);
        val[i]=max_value;
    }
    cout<<"OPTIMAL SUBSTRUCTURE:"<<endl<<"Rod Size:\t";
    for(int i=0;i<=n;++i)
        cout<<i<<"\t";
    cout<<endl<<"MAX Value\t";
    for(int i=0;i<=n;++i)
        cout<<val[i]<<"\t";
    cout<<endl;
    cout<<"Max Obtainable Price: ";
    return val[n];
}

int main()
{
    /*
        Rod Length: n=8
        Price array: [4,3,2,1,5,2,4]
    */
    int price[]= {4,3,2,1,5,2,4,0};
    int n= sizeof(price)/sizeof(int);
    cout<<cutRod(n, price)<<endl;
    return 0;
}