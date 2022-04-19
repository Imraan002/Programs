#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<char,int> mp;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    int t,x1,y1,x2,y2;
    cin>>t>>x1>>y1>>x2>>y2;
    string str;
    cin>>str;

    if(x2-x1>=0 && y2-y1>=0)
    {
        mp.insert({'E',abs(x2-x1)});
        mp.insert({'N',abs(y2-y1)});
    }
    else if(x2-x1>=0 && y2-y1<0)
    {
        mp.insert({'E',abs(x2-x1)});
        mp.insert({'S',abs(y2-y1)});
    }
    else if(x2-x1<0 && y2-y1>=0)
    {
        mp.insert({'W',abs(x2-x1)});
        mp.insert({'N',abs(y2-y1)});
    }
    else{
     mp.insert({'W',abs(x2-x1)});
     mp.insert({'S',abs(y2-y1)});
 }
 
for(auto k:mp)
{
    cout<<k.first<<k.second;
}
int ans=0;
int i=0;
while(i<str.size() && mp.size()!=0)
{
   
    if(str[i]=='N' && mp.find('N')!=mp.end())
    {
        mp['N']--;
        if(mp['N']==0)
        {
            mp.erase('N');
        }
       
    }
    else if(str[i]=='S' && mp.find('S')!=mp.end())
    {
        mp['S']--;
         if(mp['S']==0)
        {
            mp.erase('S');
        }
    }
    else if(str[i]=='E'&& mp.find('E')!=mp.end())
    {
        mp['E']--;
         if(mp['E']==0)
        {
            mp.erase('E');
        }
    }
    else if(str[i]=='W' && mp.find('W')!=mp.end()){
        mp['W']--;
         if(mp['W']==0)
        {
            mp.erase('W');
        }
    }
    ans++;
    i++;
}
cout<<i;
for(auto k:mp)
{
    cout<<k.first<<k.second;
}
bool flag=true;
for(auto k:mp)
{
    if(k.second!=0)
    {
        flag=false;
        break;
    }
}
if(flag==false)
    cout<<-1<<"\n";
else
    cout<<ans<<"\n";
return 0;
}