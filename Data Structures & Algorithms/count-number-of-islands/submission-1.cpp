class Solution {
public:
    void markZero(vector<vector<char>> & grid,int row,int col,int rows,int cols){
        if(row<0 || row>=rows ||col<0 ||col>=cols || grid[row][col]=='0')
            return ;
        cout<<row<<" "<<col<<endl;
        grid[row][col]='0';
        markZero(grid,row+1,col,rows,cols);
        markZero(grid,row-1,col,rows,cols);
        markZero(grid,row,col+1,rows,cols);
        markZero(grid,row,col-1,rows,cols);

        
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size(),ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1')
                {
                    ans++;
                    markZero(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};
