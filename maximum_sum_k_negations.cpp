#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int arr[],int n,int k)
{
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0 && k>0)
        {
            arr[i]=-arr[i];
            k--;
        }
    }
    int sum=accumulate(arr,arr+n,0);
    int minele=*min_element(arr,arr+n);
    if(k&1)
    {
        sum-=2*minele;
    }
    return sum;
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
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<solve(arr,n,k);
    return 0;
}