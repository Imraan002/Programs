#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int arr[N];
int partition(int l, int mid, int r)
{
    int inv_cnt=0;
    int i = l;
    int j = mid + 1;
    int k = l;
    vector<int> temp(N);
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else                                    //inversion count
        {

            temp[k++] = arr[j++];
            inv_cnt+=(mid+1)-i;
        }
    }
    while (j <= r)
    {
        temp[k++] = arr[j++];
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    for (int k = l; k <= r; k++)
    {
        arr[k] = temp[k];
    }
    return inv_cnt;
}
int mergesort(int l, int r)
{
    if (l >= r)
        return 0;
    int inv_cnt = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv_cnt += mergesort(l, mid);
        inv_cnt += mergesort(mid + 1, r);
        inv_cnt +=partition(l, mid, r);
    }
    return inv_cnt;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << mergesort(0, n - 1);

    return 0;
}