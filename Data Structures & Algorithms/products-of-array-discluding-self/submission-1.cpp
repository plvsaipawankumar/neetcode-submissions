class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,n=nums.size(),count_zero=0,product=1;
        vector<int> ans(n,0);
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
                count_zero++;
            else
                product*=nums[i];
        }
        if(count_zero>1)
            return ans;
        for(i=0;i<n;i++)
        {
            if(count_zero==1)
            {
                if(nums[i]==0)
                    ans[i]=product;
            }
            else{
                ans[i]=(int)((int)product/(int)nums[i]);
            }
        }
        return ans;
    }
};
