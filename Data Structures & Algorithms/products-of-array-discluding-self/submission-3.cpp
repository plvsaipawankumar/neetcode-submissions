class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i,n=nums.size(),product=1,zero=0;
        vector<int> ans(n,0);
        for(i=0;i<n;i++){
            if(nums[i]!=0){
                product*=nums[i];
            }
            else{
                zero++;
            }
        }
        if(zero>=2)return ans;
        for(i=0;i<n;i++){
            if(zero==1){
                if(nums[i]==0)
                    ans[i]=product;
            }
            else{
                ans[i]=product/nums[i];
            }
        }
        return ans;
    }
};
