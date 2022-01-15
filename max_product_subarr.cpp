#include<bits/stdc++.h>
using namespace std;
#define ll long long
int solve(int arr[],int n)
{
    int cnt_zero=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            cnt_zero++;
        }
    }
    if(cnt_zero==n)
        return 0;
    int max_res=INT_MIN;
    int max_ending=1;
    int min_ending=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            max_ending=max(max_ending,arr[i]*max_ending);
            min_ending=min(1,min_ending*arr[i]);
        }
        else if(arr[i]<0)
        {
            int temp=max_ending;
            max_ending=max(1,min_ending*arr[i]);
            min_ending=temp*arr[i];
        }
        else{
            max_ending=1;
            min_ending=1;
        }
        max_res=max(max_res,max_ending);
    }
    if(max_res==1)
        max_res=0;
    return max_res;
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
    cout<<solve(arr,n);
    return 0;
}