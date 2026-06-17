class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i,n=nums.size(),sum=0,ans=0;
        map<int,int> store;
        store[0]=1;
        for(i=0;i<n;i++){
            sum+=nums[i];
            ans+= store[sum-k];
            store[sum]++;
        }
        return ans;
    }
};