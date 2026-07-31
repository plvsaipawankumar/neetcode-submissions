class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),0) ;
        int i,n=nums.size(),product=1,zero_count=0;

        for(int num : nums){
            if(num==0){
                zero_count++;
            }
            else{
                product = product * num;
            }
        }   
        if(zero_count>=2)
            return ans;
        for(int i=0;i<nums.size();i++){
            if(zero_count==1){
                if(nums[i]==0)
                    ans[i]=product;
                continue;
            }
            ans[i]=product/nums[i];
        }
        return ans;
    }
};
