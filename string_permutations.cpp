// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;


// Function to print permutations of string
// This function takes three parameters:
// 1. String
// 2. Starting index of the string
// 3. Ending index of the string.
vector<string> permute(string a, int l, int r)
{
	// Base case
    vector<string> temp;
	if (l == r)
		temp.push_back(a);
	else
	{
		// Permutations made
		for (int i = l; i <= r; i++)
		{

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l+1, r);

			//backtrack
			swap(a[l], a[i]);
		}
	}
    return temp;
}

// Driver Code
int main()
{
     #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);
	string str = "ABC";
	int n = str.size();
	vector<string> ans=permute(str, 0, n-1);
    for(auto k:ans)
    {
        cout<<k<<endl;
    }
	return 0;
}

// This is code is contributed by rathbhupendra
