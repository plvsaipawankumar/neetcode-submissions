class Solution {
public:
    vector<vector<int>> dp;
    int pathSum(vector<vector<int>>& grid ,int row,int col,int n,int m){
        if(row<0 || col<0 ||row>=n || col>=m){
            return INT_MAX-1000;
        }
        if(row == n-1 && col == m-1)
            return grid[row][col];
        if(dp[row][col]!=-1)
            return dp[row][col];
        cout<<row<<" "<<col<<" "<<grid[row][col]<<endl;
        int left = pathSum(grid,row+1,col,n,m);
        int down = pathSum(grid,row,col+1,n,m);
        cout<<left<<" "<<down<<endl;
        dp[row][col]=min(left,down)+grid[row][col];
        return dp[row][col];
    }
    int minPathSum(vector<vector<int>>& grid) {
        dp= vector<vector<int>>(grid.size(),vector<int>(grid[0].size(),-1));
        return pathSum(grid,0,0,grid.size(),grid[0].size());
    }
};