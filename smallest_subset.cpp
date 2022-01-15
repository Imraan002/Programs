#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    sort(arr,arr+n);
    int j=n-1;
    int total_sum=accumulate(arr,arr+n,0);
    int temp_sum=0;
    int ans=0;
    while(true)
    {
        total_sum-=arr[j];
        temp_sum+=arr[j];
        ans++;
        j--;
        if(temp_sum>total_sum)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}