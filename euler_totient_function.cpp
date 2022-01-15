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
    int count=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            count=count-count/i;
        }
        while(n%i==0)
        {
            n=n/i;
        }                                          //phi(n)= n * (1-1/p1) * (1-1/p2) *.....(1-1/pk) where p1,p2,..pk are prime factors of n
    }
    if(n>1)
    {
        count=count-count/n;
    }
    cout<<count<<endl;
   
    return 0;
}