#include<bits/stdc++.h>
using namespace std;
#define int long long
int len;
const int N=2e5+2;
struct node
{
	int left,right,idx;
};
node qry[N];
bool comp(node q1,node q2)
{
	if(q1.left/len==q2.left/len)
	{
		return q1.right>q2.right;
	}
	else return q1.left/len<q2.left/len;
}
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	vector<int> arr(n);
	len=ceil(sqrtl(n));
	for(auto &x:arr)
	{
		cin>>x;
	}
	int q;
	cin>>q;
	vector<int> ans(q);
	for(int i=0;i<q;i++)
	{
		cin>>qry[i].left>>qry[i].right;
		qry[i].idx=i;
	}
	sort(qry,qry+q,comp);
	int curr_l=0,curr_r=-1,curr_ans=0;
	int l,r;
	vector<int> freq(10 * N, 0);
	for(int i=0;i<q;i++)
	{
		l=qry[i].left;
		r=qry[i].right;
		l--;
		r--;
		while(curr_r<r)
		{
			curr_r++;
			freq[arr[curr_r]]++;
			if(freq[arr[curr_r]]==1)
			{
				curr_ans++;
			}
		}
		while(curr_l>l)
		{
			curr_l--;
			freq[arr[curr_l]]++;
			if(freq[arr[curr_l]]==1)
			{
				curr_ans++;
			}
		}
		while(curr_r>r)
		{
			freq[arr[curr_r]]--;
			if(freq[arr[curr_r]]==0)
			{
				curr_ans--;
			}
			curr_r--;
		}
		while(curr_l<l)
		{
			freq[arr[curr_l]]--;
			if(freq[arr[curr_l]]==0)
			{
				curr_ans--;
			}
			curr_l++;
		}
		ans[qry[i].idx]=curr_ans;
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}