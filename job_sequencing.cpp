#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Job{
    char id;
    int deadline,profit;
};
bool comp(Job a,Job b)
{
    return a.profit>b.profit;
}
void solve(Job arr[],int n)
{
    bool temp[n];
    for(int i=0;i<n;i++)
    {
        temp[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].deadline-1;j>=0;j--)
        {
            if(temp[j]==false)
            {
                cout<<arr[i].id<<" ";
                temp[j]=true;
                break;
            }
        }
    }

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
        char x;
        int y,z;
        cin>>x>>y>>z;
        arr[i].id=x;
        arr[i].deadline=y;
        arr[i].profit=z;
    }
    sort(arr,arr+n,comp);
    solve(arr,n);
    return 0;
}