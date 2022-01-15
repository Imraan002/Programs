#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool two_pointer_sum(int arr[],int sum,int i,int n)
{
    int j = n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]<sum)
        {
            i++;
        }
        else if(arr[i]+arr[j]>sum)
        {
            j--;
        }
        else if(arr[i]+arr[j]==sum)
        {
            return true;
        }
    }                                           //find if three elements such that there sum is 0 exists;
    return false;
}
bool solve(int arr[],int n)
{
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        if(two_pointer_sum(arr,-arr[i],i+1,n))
            return true;
    }
    return false;
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
    bool res = solve(arr,n);
    if(res)
        cout<<"found"<<endl;
    else
        cout<<"not found"<<endl;
    return 0;
}