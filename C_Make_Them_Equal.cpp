#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t ;
    cin>>t;
    while(t--)
    {
        ll int n;
        cin>>n;
        char ch;
        cin>>ch;
        string str;
        cin>>str;
        bool check=false;
        int idx=-1;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==ch)
            {
                idx=i;
            }
            if(str[i]!=ch)
                check=true;
        }
        if(check==false)
        {
            cout<<0<<"\n";
            continue;
        }
        if(idx==-1)
        {
            cout<<2<<"\n";
            cout<<n-1<<" "<<n<<"\n";
        }
        else if(idx==n-1)
        {
            cout<<1<<"\n";
            cout<<n<<"\n";
        }
        else if(idx>=n/2)
        {
            cout<<1<<"\n";
            cout<<idx+1<<"\n";
        }
        else 
        {
            cout<<2<<"\n";
            cout<<n-1<<" "<<n<<"\n";
        }
    }
return 0;
}