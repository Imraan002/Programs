#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct block{
    int value,weight;
};
bool comp(block a,block b)
{
    double val1=((double)a.value/a.weight);
    double val2=((double)b.value/b.weight);
    return val1>val2;
}
double fnpsk(block arr[],int n,int wt)
{
    sort(arr,arr+n,comp);
    double currweight=0;
    double profit=0;
    for(int i=0;i<n;i++)
    {
        if(currweight+arr[i].weight<=wt)
        {
            profit+=arr[i].value;
            currweight+=arr[i].weight;
        }
        else{
            double remwt=wt-currweight;
            profit+=((double)remwt/arr[i].weight)*arr[i].value;
        }
    }
    return profit;
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
    block arr[n];
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr[i].value=x;
        arr[i].weight=y;
    }
    int wt;
    cin>>wt;
    cout<<fnpsk(arr,n,wt);
    return 0;
}