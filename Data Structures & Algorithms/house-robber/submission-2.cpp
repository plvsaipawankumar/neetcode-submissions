class Solution {
public:
    vector<int> dp;
    int dfs(vector<int> nums,int pointer)
    {
        int n=nums.size();
        if(pointer>=n)
            return 0;
        if(dp[pointer]!=INT_MIN)
            return dp[pointer];
        return dp[pointer] = max(dfs(nums,pointer+1),dfs(nums,pointer+2)+nums[pointer]);
    }
    int rob(vector<int>& nums) {
        int i,n =nums.size();
        dp.resize(n,INT_MIN);
        return dfs(nums,0);
    }
};
