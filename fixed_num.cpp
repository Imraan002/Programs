#include<bits/stdc++.h>
using namespace std;
#define ll long long
void shift(vector<ll int> &arr,ll int l,ll int r)
{
	 ll int var = arr[l];
        for (int i = l + 1; i <= r; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[r] = var;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
    	ll int n,k;
        cin>>n>>k;
        vector<ll int> arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
         if(n==k)
        {
            for(auto k:arr)
            {
                cout<<k<<" ";
            }
            cout<<endl;
            continue;
        }
        if(n-k<=1)
        {
            cout<<-1<<endl;
            continue;
        }
       
        shift(arr,0,n-k-1);
        for(ll int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    
    }
    return 0;
}