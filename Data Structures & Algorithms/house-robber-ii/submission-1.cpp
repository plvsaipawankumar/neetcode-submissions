class Solution {
public:
    vector<int> maxrob;
    int dfs(vector<int> nums)
    {
        int i,n= nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(i=2;i<nums.size();i++)
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return nums[0];
        
        return max(dfs(vector<int>(nums.begin()+1,nums.end())),dfs(vector<int>(nums.begin(),nums.end()-1)));
    }
};
