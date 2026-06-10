class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> store;
        int i,n=nums.size(),ans=0;
        for(i=0;i<n;i++){
            if(store[nums[i]])
                continue;
            store[nums[i]] = store[nums[i]-1]+store[nums[i]+1]+1;
            store[nums[i]-store[nums[i]-1]] = store[nums[i]];
            store[nums[i]+store[nums[i]+1]] = store[nums[i]];
            ans = max(ans,store[nums[i]]);
        }
        return ans;
    }
};
