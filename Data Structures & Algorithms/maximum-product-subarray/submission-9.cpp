class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i,n=nums.size();
        int ans=nums[0],maxans=1,minans=1,temp;
        for(i=0;i<n;i++)
        {
            temp = maxans*nums[i];
            maxans=max(max( maxans*nums[i],minans*nums[i]),nums[i]);
            minans=min(min( temp,minans*nums[i]),nums[i]);
            ans=max(ans,maxans);
        }
        return ans;
    }
};
