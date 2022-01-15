#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Job{
    int start,finish,profit;
   
};
bool comp(Job a,Job b)
{
    return a.finish<b.finish;
}
int profit(Job arr[],int n)
{
    int* dp=new int[n];
    dp[0]=arr[0].profit;
    for(int i=1;i<n;i++)
    {
        int including=arr[i].profit;
        int idx=-1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j].finish<=arr[i].start)
            {
                idx=j;
                break;
            }
        }
        if(idx!=-1)
        {
            including+=dp[idx];
        }
        dp[i]=max(dp[i-1],including);    
    }
return dp[n-1];
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
    Job arr[n];
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        arr[i]={x,y,z};
    }
    sort(arr,arr+n,comp);
    cout<<profit(arr,n);
    return 0;
}