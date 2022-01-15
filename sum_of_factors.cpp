#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
int arr[N];
int binary_expo(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a;
        }
        a=a*a;
        b=b/2;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else
    {
        for (int i = 0; i < N; i++)
        {
            arr[i] = i;
        }
        for (int i = 2; i * i < N; i++)
        {
            if (arr[i] == i) //factores in logn
            {
                for (int j = i * 2; j < N; j = j + i)
                {
                    if (arr[j] == j)
                    {
                        arr[j] = i;
                    }
                }
            }
        }
        vector<int> ans;
        while (n > 1)
        {
            ans.push_back(arr[n]);
            n = n / arr[n];
        }
        int cnt=1;
        int prod=1;
        int k;
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]==ans[i-1])
            {
                cnt++;
            }
            else{
                 k=binary_expo(ans[i-1],cnt+1);
                prod*=(k-1)/(ans[i-1]-1);
                cnt=1;
            }
        }
        k=binary_expo(ans[ans.size()-1],cnt+1);
        prod*=(k-1)/(ans[ans.size()-1]-1);
        cout<<prod<<endl;
    }

    return 0;
}