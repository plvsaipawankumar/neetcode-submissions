class Solution {
public:
    set<pair<int,int>> passed;
    void traversal(vector<vector<int>>& grid,int dist,int i,int j)
    {
        cout<<"i : "<<i<<" j : "<<j<<endl;
        if((grid.size()==i)||(grid[0].size()==j)||(i<0)||(j<0)||(grid[i][j]==-1)||(grid[i][j]<dist))
            return ;
        passed.insert({i,j});
        grid[i][j]=min(dist,grid[i][j]);
        traversal(grid,dist+1,i+1,j);
        traversal(grid,dist+1,i-1,j);
        traversal(grid,dist+1,i,j+1);
        traversal(grid,dist+1,i,j-1);
    }
    void print(vector<vector<int>> grid)
    {
        int i,j,n=grid.size(),m=grid[0].size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    traversal(grid,0,i,j);
            }
        }
        print(grid);
    }
};
