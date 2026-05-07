class Solution {
public:
    vector<int> maxrob;
    int dfs(vector<int> & nums,int n ,int i)
    {
        if(i>=n) return 0;
        if(maxrob[i]!=INT_MIN) return maxrob[i];
        return maxrob[i]=max(dfs(nums,n,i+2),dfs(nums,n,i+3))+nums[i];
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        maxrob.resize(n,INT_MIN);
        return max(dfs(nums,n,0),dfs(nums,n,1));
    }
};
