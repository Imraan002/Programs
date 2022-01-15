#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
vector<int> fenwick_tree(N,0);
int sum(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=fenwick_tree[idx];
        idx=idx-(idx&-idx);
    }
    return sum;
}
void update(int idx,int val)                                    //fenwick tree
{
    while(idx<N)
    {
        fenwick_tree[idx]+=val;
        idx=idx+(idx&-idx);
    }
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
    int arr[n+1];
   for(int i=1;i<=n;i++)
   {
       cin>>arr[i];
   }
    for(int i=1;i<=n;i++)
    {
        update(i,arr[i]);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
             int l,r;
             cin>>l>>r;
             cout<<sum(r)-sum(l-1)<<endl;
        }
        else{
            int idx,val;
            cin>>idx>>val;            
            update(idx,val);
        }
       

    }
    return 0;
}