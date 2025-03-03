#include<iostream>
#include<vector>
using namespace std;

bool issafe(vector<string>&board, int row,int col, int n)
{
    //horizontal
    for(int i=0; i<n; i++)
    {
        if(board[row][i]=='Q')
            return false;
    }
    // vertical
    for(int i=0; i<n; i++)
    {
        if(board[i][col]=='Q')
            return false;
    }
    //left diagonal
    for(int i=row,j=col; i>=0&&j>=0; i--,j--)
    {
        if(board[i][j]=='Q')
            return false;
    }
    //right diagonal
    for(int i=row,j=col; i>=0&&j<n; i--,j++)
    {
        if(board[i][j]=='Q')
            return false;
    }

    return true;
}

void nqueen(vector<string>board, int row, int n,vector<vector<string>>&ans)
{
    if(row==n)
    {
        ans.push_back({board});
        return;
    }
    for(int j=0; j<n; j++)
    {
        if(issafe(board,row, j,n))
        {
            board[row][j]='Q';
            nqueen(board, row+1, n,ans);
            board[row][j]='.';
        }
    }
}

vector<vector<string>>solvenqueen(int n)
{
    vector<string>board(n, string(n,'.'));

    vector<vector<string>>ans;

    nqueen(board, 0, n,ans);
    return ans;

}
void display(vector<vector<string>> ans)
{
    cout<<"Solution: "<<ans.size()<<endl;
    for( const auto &board: ans)
    {
        for( const auto &row: board)
        {
            cout<<row<<endl;

        }
        cout<<"************"<<endl;
    }



}


int main()
{
    int n;
    cout<< "Enter the number: ";
    cin>>n;
    vector<vector<string>>ans=solvenqueen(n);
    display(ans);

}

