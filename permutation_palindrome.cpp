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
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        map<char,int> mp;
        map<char,multiset<int>> mp2;
        for(int i=0;i<str.length();i++)
        {
            mp[str[i]]++;
            mp2[str[i]].insert(i+1);
        }
        vector<char> res(str.length());
        int odd_cnt=0;
        for(auto k:mp)
        {
            if(k.second&1)
            {
                odd_cnt++;
            }
        }
        if(odd_cnt>1)
        {
            cout<<-1<<endl;
            continue;
        }
        int i=0;
        int j=str.length()-1;
    for(auto k:mp)
    {
        if(k.second&1)
        {
            res[str.length()/2]=k.first;
            mp[k.first]--;
        }
        while(i<j && mp[k.first]!=0)
        {
            res[i++]=k.first;
            res[j--]=k.first;
            mp[k.first]-=2;
        }
    }
    vector<int> res2;
    for(auto k:res)
    {
        res2.push_back(*mp2[k].begin());
        mp2[k].erase(mp2[k].begin());
    }
    for(auto k:res2)
    {
        cout<<k<<" ";
    }
    cout<<endl;
    }
    return 0;
}