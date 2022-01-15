#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int arr[],int n)
{
    int zro_cnt=0;
    int neg_cnt=0;
    int prod=1;
    int maxneg=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            zro_cnt++;
            continue;
        }
        else if(arr[i]<0)
        {
            neg_cnt++;
            maxneg=max(maxneg,arr[i]);
        }
        prod*=arr[i];
    }
    if(zro_cnt==n)
    {
        return 0;
    }
    else if(neg_cnt==1 && zro_cnt==n-1)
    {
        return 0;
    }
    return prod/maxneg;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(auto &k:arr)
    {
        cin>>k;
    }
    cout<<solve(arr,n);
    return 0;
}