class Solution {
public:
    int n,m;
    void print(vector<vector<char>> board)
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void dfs(vector<vector<char>> & board,int r,int c)
    {
        cout<<"r : "<<r<<"c : "<<c<<endl;
        if(r<0 || r>=n || c<0 || c>=m || board[r][c]!='O')
            return ;
        board[r][c]='T';
        dfs(board,r+1,c);
        dfs(board,r,c+1);
        dfs(board,r-1,c);
        dfs(board,r,c-1);
    }
    void captureo(vector<vector<char>> & board)
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][m-1]=='O')
                dfs(board,i,m-1);
        }
        for(i=0;i<m;i++)
        {
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[n-1][i]=='O')
                dfs(board,n-1,i);
        }
        print(board);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='T')
                    board[i][j]='O';
            }
        }
        //print(board);
    }
    void solve(vector<vector<char>>& board) {
        n=board.size(),m=board[0].size();
        cout<<" n :" <<n<<" m: "<<m<<endl;
        captureo(board);
    }
};
