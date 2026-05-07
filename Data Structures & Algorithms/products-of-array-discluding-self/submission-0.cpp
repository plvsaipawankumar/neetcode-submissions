class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long i,j,product=1,n=nums.size(),zero_count=0;
        vector<int> ans(n,0);
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
                zero_count++;
            else
                product *= nums[i];
        }
        if(zero_count>1)
        {
            return ans;
        }
        else if(zero_count==1)
        {
            for(i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    ans[i]=product;
                }
            }
        }
        else
        {
            for(i=0;i<n;i++)
            {
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};
