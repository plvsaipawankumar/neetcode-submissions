class Solution {
public:
    bool validthreebythree(int h ,int v,vector<vector<char>>& board)
    {
        int i,j;
        map<int,int> threetothree;
        for(i=h;i<h+3;i++)
        {
            for(j=v;j<v+3;j++)
            {
                if(board[i][j] != '.')
                {
                    if(threetothree[board[i][j]]==1)
                        return false;
                    threetothree[board[i][j]]++;
                }
            }
        }
        return true;
    }

    bool threebythree(vector<vector<char>>& board)
    {
        int i,j;
        for(i=0;i<9;i+=3)
        {
            for(j=0;j<9;j+=3)
            {
                if(!validthreebythree(i,j,board))
                    return false;
            }
        }
        return true;
    }

    bool validhorizontalvertical(vector<vector<char>>& board)
    {
        map<char,int> hor,ver;
        int i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(hor[board[i][j]]==1)
                        return false;
                    hor[board[i][j]]++;
                }
                
                if(board[j][i] != '.')
                {
                    if(ver[board[j][i]]==1)
                        return false;
                    ver[board[j][i]]++;
                }
            }
            hor.clear();
            ver.clear();
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(!validhorizontalvertical(board))
            return false;
        else
            return threebythree(board);

    }
};
