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
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string str;
        cin>>str;
        int one(0),zero(0);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='0')
            {
                zero++;
            }
            else if(str[i]=='1'){
                one++;
            }
        }
        
        cout<<zero*a+one*b<<endl;
    }
    return 0;
}