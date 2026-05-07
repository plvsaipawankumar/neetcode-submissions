class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
                if((i==(m-1) )&& (j==(n-1) ))
                    continue;
                int row = ((i+1)<m)?dp[i+1][j]:0;
                int col = ((j+1)<n)?dp[i][j+1]:0;
                dp[i][j]=row+col;
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        return dp[0][0];
    }
};
