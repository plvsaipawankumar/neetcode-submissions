class Solution {
public:
    void makeItOcean(vector<vector<char>>& grid,int i,int j)
    {
        cout<<"i :"<<i<<" j :"<<j<<endl;
        if(grid.size()==i || grid[0].size()==j || i<0 ||j<0 ||grid[i][j]=='0')
        return ;
        grid[i][j]='0';
        makeItOcean(grid,i+1,j);
        makeItOcean(grid,i-1,j);
        makeItOcean(grid,i,j+1);
        makeItOcean(grid,i,j-1);
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size(),ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    makeItOcean(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
