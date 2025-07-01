class Solution {
public:
bool isSafe(int row, int col,vector<vector<char>>&board,char num)
{
    //check the row
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==num)
        return false;
    }

    //check the col
    for(int i=0;i<9;i++)
    {
        if(board[i][col]==num)
        return false;
    }

    int startRow=3*(row/3);
    int startCol=3*(col/3);
    for(int i=startRow;i<startRow+3;i++)
    {
        for(int j=startCol;j<startCol+3;j++)
        {
            if(board[i][j]==num)
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>&board)
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(board[row][col]=='.')
            {
                //try placing digits from 1 to 9
                for(char num='1';num<='9';num++)
                {
                    if(isSafe(row,col,board,num))
                    {
                        board[row][col]=num;

                        if(solve(board))
                        return true;

                        //backtrack
                        board[row][col]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};