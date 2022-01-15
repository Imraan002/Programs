#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int arr[N];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<N;i++)
    {
        arr[i]=i;
    }
    for(int i=2;i*i<N;i++)
    {
        if(arr[i]==i)               //factores in logn
        {
            for(int j=i*2;j<N;j=j+i)
            {
                if(arr[j]==j)
                {
                    arr[j]=i;
                }
            }
        }
    }
    vector<int> ans;
    while(n>1)
    {
        ans.push_back(arr[n]);
        n=n/arr[n];
    }
    for(auto k:ans)
    {
        cout<<k<<"*";
    }
    cout<<1;
    return 0;
}