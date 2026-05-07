class Solution {
public:
    vector<int> maxrob;
    int dfs(vector<int> nums)
    {
        int i,n=nums.size();
        maxrob[0]=nums[0];
        maxrob[1]=max(nums[1],nums[0]);
        for(i=2;i<n;i++)
            maxrob[i]=max(maxrob[i-1],nums[i]+maxrob[i-2]);
        return maxrob[n-1];
    }
    int rob(vector<int>& nums) {
        int i,n= nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        maxrob.resize(n,INT_MIN);
        return max(dfs(vector<int>(nums.begin()+1,nums.end())),dfs(vector<int>(nums.begin(),nums.end()-1)));
    }
};
