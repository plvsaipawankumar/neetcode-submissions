class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i,n=nums.size(),ans=nums[0],total=nums[0];
        for(i=1;i<n;i++)
        {
            if(ans<0)
                ans=0;
            ans+=nums[i];
            total=max(total,ans);
        }
        return total;
    }
};
