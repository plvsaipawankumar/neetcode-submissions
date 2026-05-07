class Solution {
public:
    int size ;
    vector<vector<string>> ans;
    void show(vector<string> board)
    {
        int i,j;
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                cout<<board[i][j];
            }
            cout<<endl;
        }
        return ;
    }
    bool checkpos(vector<string> board,int row ,int col)
    {
        int i=row,j=col;
        for(i=0;i<size;i++)
            if(board[row][i]=='Q'&& i!=col)
                return false;
        cout<<"col okay"<<endl;
        i=row,j=col;
        for(i=0;i<size;i++)
            if(board[i][col]=='Q' && i!=row)
                return false; 
        cout<<"row okay"<<endl;

        i=row,j=col;
        while(i<size && j<size)
        {
            if(board[i][j]=='Q' && i!=row && j!=col)
                return false;
            i++,j++;
        }
        cout<<"++dia okay"<<endl;

        i=row,j=col;
        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q' && i!=row && j!=col)
                return false;
            i--,j--;
        }
        cout<<"--dia okay"<<endl;

        i=row,j=col;
        while(i>=0 && j<size)
        {
            if(board[i][j]=='Q' && i!=row && j!=col)
                return false;
            i--,j++;
        }
        cout<<"-+di okay"<<endl;

        i=row,j=col;
        while(i<size && j>=0 && i!=row && j!=col)
        {
            if(board[i][j]=='Q')
                return false;
            i++,j--;
        }
        cout<<"+-dia okay"<<endl;

        return true;
    }
    void queens(vector<string> board,int i)
    {
        if(i==size)
        {
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<size;j++)
        {
            board[i][j]='Q';
            if(checkpos(board,i,j))
            {
                cout<<"i : "<<i<<",j : "<<j<<endl;
                show(board);
                queens(board,i+1);
            }
            board[i][j]='.';
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        int i,j;
        vector<string> board;
        string s="";
        for(i=0;i<size;i++)
            s+='.';
        for(i=0;i<size;i++)
            board.push_back(s);
        show(board);
        queens(board,0);
        return ans;
    }
};
