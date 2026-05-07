class Solution {
public:
    set<pair<int,int>> passed;
    int rottenTime(vector<vector<int>> & grid,int time,int i,int j)
    {
        int itr,level=-1,n,k,l;
        bool flag=false;
        queue<pair<int,int>> que;
        vector<vector<int>> direction ={{0,1},{0,-1},{1,0},{-1,0}};
        for(k=0;k<grid.size();k++)
        {
            for(l=0;l<grid[0].size();l++)
            {
                if(grid[k][l]==2)
                    que.push({k,l});
            }
        }
        while(!que.empty())
        {
            n=que.size();
            for(itr=0;itr<n;itr++)
            {
                pair<int,int> p= que.front();que.pop();
                cout<<p.first<<","<<p.second<<" | " ;
                for(auto &dir :direction)
                {
                    int r= p.first+dir[0];
                    int c= p.second+dir[1];
                    //cout<<"(r,c) : "<<r<<","<<c;
                    if(r>=0 && c>=0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1)
                    {
                        flag=true;
                        que.push({r,c});
                        grid[r][c]=2;
                    }
                        
                }
            }
            level++;
            cout<<que.empty()<<" "<<level<<" "<<flag<<endl;
        }
        cout<<"return level :"<<level<<endl;
        return level;
    }
    int print(vector<vector<int>> grid)
    {
        int i,j, n=grid.size(),m=grid[0].size();
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==1)return 1;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int i,j,n=grid.size(),m=grid[0].size(),ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    //ans=max(rottenTime(grid,0,i,j),ans);
                    ans=rottenTime(grid,0,i,j);
                }
                if(ans!=0)
                    break;
            }
            if(ans!=0)
                break;
        }
        cout<<"ans : "<<ans<<endl;
        return print(grid)?-1:ans;
    }
};
