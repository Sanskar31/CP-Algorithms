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
#define F(i,a,b) for(string i = (string)(a); i <= (string)(b); i++)
#define RF(i,a,b) for(string i = (string)(a); i >= (string)(b); i--)
#define INF 100009
#define mod 1000000007
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second

void longestIncSubSeqSum(int arr[], int n)
{
    int max_sum[n], prev_index[n];
    for(int i=0;i<n;++i)
        max_sum[i]=arr[i], prev_index[i]=i;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(arr[j]>arr[i])
            {
                if(max_sum[j]<max_sum[i]+arr[j])
                {
                    max_sum[j]=max_sum[i]+arr[j];
                    prev_index[j]= i;
                }
            }
        }
    }
    int sum=0, max_index=0, max_so_far=INT_MIN;
    for(int i=0;i<n;++i)
    {
        if(max_sum[i]>max_so_far)
        {
            max_so_far=max_sum[i];
            max_index=i;
        }
    }
    sum= max_sum[max_index];
    stack<int> s;
    int i= max_index;
    while(1)
    {
        if(prev_index[i]==i)
        {
            s.push(arr[i]);
            break;
        }
        s.push(arr[i]);
        i=prev_index[i];
    }
    cout<<"Longest Increasing Sub Sequence With Max Sum is: ";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"MAX SUM is: "<<sum<<endl;
}

int main()
{
    /*
        Increasing SubSequence With Maximum Sum
        Array= 11,5,13,2,1,7,8,21,23,12,15
    */
    int arr[]= {11,5,13,2,1,7,8,21,23,12,15};
    int n= sizeof(arr)/sizeof(int);
    longestIncSubSeqSum(arr,n);
    return 0;
}