#include <bits/stdc++.h>
using namespace std;
#define ll long long
int find_d_size(vector<vector<char>> &arr, int i, int j)
{
    int left=0;
    int right=0;
    int x=i;
    int y=j;
    while(x>0 && y>0)
    {
        x--;
        y--;
        if(arr[x][y]=='.')
            break;
        if(arr[x][y]=='*' || arr[x][y]=='t')
            left++;
    }
    x=i;
    y=j;
    while(x>0 && y<arr[0].size())
    {
        x--;
        y++;
        if(arr[x][y]=='.')
            break;
        if(arr[x][y]=='*' || arr[x][y]=='t')
        {
            right++;
        }
    }
   
    return min(left,right);
}
void mark_d(vector<vector<char>> &arr, int i, int j,int temp)
{   arr[i][j]='t';
    int x=i;
    int y=j;
    int cnt=temp;
    while(x>0 && y>0 && temp>0)
    {
        
        x--;
        y--;
        if(arr[x][y]=='.')
            break;
        if(arr[x][y]=='t' || arr[x][y]=='*')
            arr[x][y]='t';
        temp--;
    }
    if(arr[x][y]=='t' || arr[x][y]=='*')
            arr[x][y]='t';
    x=i;
    y=j;
    while(x>0 && y<arr[0].size() && cnt>0)
    {
        x--;
        y++;
        if(arr[x][y]=='.')
            break;
        if(arr[x][y]=='t' || arr[x][y]=='*')
            arr[x][y]='t';
        cnt--;
    }
    if(arr[x][y]=='t' || arr[x][y]=='*')
            arr[x][y]='t';
}
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
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<char>> arr(n, vector<char>(m, '0'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '*')
                {
                    int temp = find_d_size(arr, i, j);
                    if (temp >= k)
                    {
                        mark_d(arr, i, j,temp);
                    }
                }
            }
        }
        int ans=-1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '*')
                {
                    ans=1;
                    break;
                }
            }
        }
        if(ans==1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}