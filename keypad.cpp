#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,string> mp; 
void mapping(void)
{
    mp[2]={"abc"};
    mp[3]={"def"};
    mp[4]={"ghi"};
    mp[5]={"jkl"};
    mp[6]={"mno"};
    mp[7]={"pqrs"};
    mp[8]={"tuv"};
    mp[9]={"wxyz"};
}
vector<string> solve(int n)
{
    vector<string> res;
    if(n==0)
    {
        res.push_back(" ");
        return res;;                    //all keypad combinations
    }
    int smallinp=n/10;
    int rem=n%10;
    vector<string> temp=solve(smallinp);
    vector<string> ans;
    for(auto k:temp)
    {
        for(auto s:mp[rem])
        {
            ans.push_back(k+s);
        }
    }
    return ans;
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
    mapping();
    vector<string> str=solve(n);
    for(auto k:str)
    {
        cout<<k<<endl;
    }
    return 0;
}