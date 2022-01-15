#include<bits/stdc++.h>
using namespace std;
#define ll long long
string solve(string str)
{
    if(str.size()==0 || str.size()==1)
     return str;
    if(str[0]=='p' && str[1]=='i')
    {
         
        return "3.14"+solve(str.substr(2,str.size()));
    }
    else{
       return str[0]+solve(str.substr(1,str.size()));
    }
    
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
   string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}