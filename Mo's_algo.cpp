#include<bits/stdc++.h>
using namespace std;
#define ll long long
int len;
struct node
{
	int left,right,idx;
};
node qry[100];
bool comp(node q1,node q2)
{
	if(q1.left/len==q2.left/len)
	{
		return q1.right>q2.right;
	}
	else return q1.left/len<q2.left/len;
}
int main()
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
	vector<int> ans(q);
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>qry[i].left>>qry[i].right;
		qry[i].idx=i;
	}
	sort(qry,qry+q,comp);
	int curr_l=0,curr_r=-1,curr_sum=0;
	int l,r;
	for(int i=0;i<q;i++)
	{
		l=qry[i].left;
		r=qry[i].right;
		l--;
		r--;
		while(curr_r<r)
		{
			curr_r++;
			curr_sum+=arr[curr_r];
		}
		while(curr_l>l)
		{
			curr_l--;
			curr_sum+=arr[curr_l];
		}
		while(curr_r>r)
		{
			curr_sum-=arr[curr_r];
			curr_r--;
		}
		while(curr_l<l)
		{
			curr_sum-=arr[curr_l];
			curr_l++;
		}
		ans[qry[i].idx]=curr_sum;
	}
	for(int i=0;i<q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}