#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> arr;
unordered_map<string,int> mp;
vector<int> func(string str)
{
	mp.insert({"zero",0});
	mp.insert({"one",1});
	mp.insert({"two",2});
	mp.insert({"three",3});
	mp.insert({"four",4});
	mp.insert({"five",5});
	mp.insert({"six",6});
	mp.insert({"seven",7});
	mp.insert({"eight",8});
	mp.insert({"nine",9});

	string temp="";
	for(int i=0;i<str.size();i++)
	{
		if(str[i]==' ')
		{
			arr.push_back(temp);
			temp.clear();
			continue;
		}
		temp=temp+str[i];
	}
	arr.push_back(temp);
	vector<int> res;
	
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]=="double")
		{
			res.push_back(mp[arr[i+1]]);
			res.push_back(mp[arr[i+1]]);
			i+=1;
		}
		else if(arr[i]=="triple")
		{
			res.push_back(mp[arr[i+1]]);
			res.push_back(mp[arr[i+1]]);
			res.push_back(mp[arr[i+1]]);
			i+=1;
		}
		else
			res.push_back(mp[arr[i]]);
		
	}
	return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);

	

	string str;
	getline(cin,str);
	vector<int> ans=func(str);
	for(auto k:ans)
	{
		cout<<k;
	}
	return 0;
}