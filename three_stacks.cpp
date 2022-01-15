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
    int n1, n2, n3,sum1(0),sum2(0),sum3(0);
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
        sum1+=arr1[i];
    }
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
        sum2+=arr2[i];
    }
    cin >> n3;
    int arr3[n3];
    for (int i = 0; i < n3; i++)
    {
        cin >> arr3[i];
        sum3+=arr3[i];
    }
   
    int top1(0), top2(0), top3(0);
    int ans = 0;
    while (true)
    {
        if (top1 == n1 || top2 == n2 || top3 == n3)
        {
            ans = 0;
            break;
        }
        if (sum1 == sum2 && sum2 == sum3)
        {
            ans = sum1;
            break;
        }
        else if (sum1 > sum2 && sum1 > sum3)
        {
            sum1 -= arr1[top1++];
        }
        else if (sum2 > sum1 && sum2 > sum3)
        {
            sum2 -= arr2[top2++];
        }
        else if (sum3 > sum2 && sum3 > sum1)
        {
            sum3 -= arr3[top3++];
        }
    }
    cout<<ans<<endl;

return 0;
}