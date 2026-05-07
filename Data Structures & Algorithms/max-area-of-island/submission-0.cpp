class Solution {
public:
    void makeItOcean(vector<vector<int>>& grid,int i,int j,int& size)
    {
        if((grid.size()==i) || (grid[0].size()==j) || (i<0) ||(j<0) || (grid[i][j]==0))
        return;

        grid[i][j]=0;
        size++;
        makeItOcean(grid,i+1,j,size);
        makeItOcean(grid,i-1,j,size);
        makeItOcean(grid,i,j+1,size);
        makeItOcean(grid,i,j-1,size);
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size(),size=0,ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    size=0;
                    makeItOcean(grid,i,j,size);
                    ans=max(ans,size);
                }
            }
        }
        return ans;
    }
};
