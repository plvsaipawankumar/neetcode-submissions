class Solution {
public:
    int dfs(vector<int> cost,vector<int>& dp,int pointer)
    {
        int n=cost.size();
        if(pointer>=n)
            return 0;
        if(dp[pointer]!=INT_MAX)
            return dp[pointer];
        return dp[pointer] = min(dfs(cost,dp,pointer+1)+cost[pointer],dfs(cost,dp,pointer+2)+cost[pointer]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i,n=cost.size();
        vector<int> dp(n,INT_MAX);
        return min(dfs(cost,dp,0),dfs(cost,dp,1));
    }
};
