#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long int m=1337;
long long get_num(vector<int> &arr)
{
    if(arr.size()==0)
        return 0;
    if(arr.size()==1)
        return arr[0];
    long long int temp=0;
    int cnt=1;
    for(int i=arr.size()-1;i>=0;i--)
    {
       temp+=(cnt*arr[i])%1140;
       cnt=(cnt*10)%1140;
    }
    return temp;
}
long long binary_expo(long long a,long long b,long long m)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    long long int ans=1;
    while(b)
    {
        if(1&b)
        {
            ans=(ans*a)%m;
        }
        a=(a*a)%m;
        b=b>>1;
    }
    return ans;
}
long long superpower(int a,vector<int> &arr)
{
    long long int b=get_num(arr);
    if(b==0)
        return 1;
    if(b==1)
        return a;
    return binary_expo(a,b,m);
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a;
    cin>>a;
    vector<int> arr;
    int k;
    while(cin>>k)
    {
        arr.push_back(k);
    }
    cout<<superpower(a,arr);
    return 0;
}