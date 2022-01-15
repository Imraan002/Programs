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
    int n,m,q;
    cin>>n>>m>>q;
    set<int> st;
    bool res=true;
    while(q--)
    {
        
        char ch;
        int i;
        cin>>ch>>i;
        if(ch=='+')
        {
            if(st.find(i)!=st.end())
            {
                res=false;
            }
            else{
                st.insert(i);
                if(st.size()>m)
                {
                    res=false;
                }
            }
        }
        else if(ch=='-'){
            if(st.find(i)==st.end())
            {
                res=false;
            }
            else{
                st.erase(i);
            }
        }

    }
    if(res)
        cout<<"consistent"<<endl;
    else
        cout<<"inconsistent"<<endl;
}
    return 0;
}