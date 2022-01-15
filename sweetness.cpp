#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
vector<int> seg_tree(4*N,INT_MIN);
 pair<int,int> arr[N];
 void build(int idx,int left,int right)
{
	if(left==right)
	{
		seg_tree[idx]=arr[left].second;
		return;
	}
	int mid=(left+right)/2;
	build(2*idx+1,left,mid);
	build(2*idx+2,mid+1,right);
	seg_tree[idx]=max(seg_tree[2*idx+1],seg_tree[2*idx+2]);
}
int query(int idx,int left,int right,int l,int r)
{
	if(left>=l && right<=r)
	{
		return seg_tree[idx];
	}
	else if(left>r || right<l)
	{
		return INT_MIN;
	}
	int mid=(left+right)/2;
	int q1=query(2*idx+1,left,mid,l,r);
	int q2=query(2*idx+2,mid+1,right,l,r);
	return max(q1,q2);
}
signed main()
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
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].first;
        }
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].second;
        }
        sort(arr,arr+n);
        build(0,0,n-1);
        int till;
        int sweet;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(d<arr[i].first)
            continue;
            till=arr[i].first;
            sweet=arr[i].second;
          
            int rem=d-till;
            int low=0;
            int high=n-1;
            int range=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(arr[mid].first<=rem)
                {
                    low=mid+1;
                    range=mid;
                }
                else{
                    high=mid-1;
                }
            }
            if(range==-1)
            {
               // sweet+=0;
            }
            else if(range>=i)
            {
                sweet+=max(query(0,0,n-1,0,i-1),query(0,0,n-1,i+1,range));
            }
            else{
                sweet+=query(0,0,n-1,0,range);
            }
            maxi=max(maxi,sweet);
            
        }
        cout<<maxi<<endl;
    }
    return 0;
}