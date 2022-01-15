#include <bits/stdc++.h>
using namespace std;
#define ll long long
void display(vector<vector<int>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[0].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool is_safe(vector<vector<int>> &board,int row,int col)
{
    int r1=row,c1=col;
    int r2=row,c2=col;
    while(row>=0)
    {
        if(board[row][col]==1)
            return false;
        row--;
    }
    while(r1>=0 && c1>=0)
    {
        if(board[r1][c1]==1)
            return false;
        r1--;
        c1--;
    }
    while(r2>=0 && c2<board[0].size())
    {
        if(board[r2][c2]==1)
            return false;
        r2--;
        c2++;
    }
    return true;
}
void N_queens(vector<vector<int>> &board,int row)
{
    if(row==board.size())
    {
        display(board);
        cout<<"\n\n";
        return;
    }
    for(int i=0;i<board[0].size();i++)
    {
        if(is_safe(board,row,i))
        {
            board[row][i]=1;
            N_queens(board,row+1);
            board[row][i]=0;
        }
    }
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
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    N_queens(board,0);
   
return 0;
}