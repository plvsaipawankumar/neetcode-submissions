class Solution {
public:
    vector<int> dp;
    int houserob(vector<int> & nums,int curr){
        if(curr>=nums.size())return 0;
        if(dp[curr]!=INT_MIN)return dp[curr];
        return dp[curr]=max(houserob(nums,curr+2)+nums[curr],houserob(nums,curr+1));
    }
    int rob(vector<int>& nums) {
        int i,n =nums.size();
        dp.resize(n,INT_MIN);
        return houserob(nums,0);
    }
};
