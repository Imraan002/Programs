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
    ll int t;
    cin>>t;
    while(t--)
    {
        ll int a,s;
        cin>>a>>s;
        string ans="";
        bool flag=true;
        while(s>0)
        {
            if(s%10 >= a%10)
            {
                
                ans=to_string((s%10-a%10))+ans;
                
                
                a=a/10;
                s=s/10;
            }
            else{
                ll int num1=s%100;
                ll int num2=a%10;
                if(num1-num2<0 || num1-num2>9)
                {
                    flag=false;
                    break;
                }
                else{
                    ans=to_string(num1-num2)+ans;
                    s=s/100;
                    a=a/10;
                }
            }
        }
        if(s<=0 && a!=0)
        {
            flag=false;
        }
        if(flag==false)
        {
            cout<<-1<<"\n";
        }
        else{
            ll int k=stoll(ans);
            cout<<k<<"\n";
        }
    }
return 0;
}