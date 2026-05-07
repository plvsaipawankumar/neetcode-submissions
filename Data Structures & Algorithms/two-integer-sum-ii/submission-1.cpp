class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j,n=nums.size(),flag=0;
        i=0,j=n-1;
        map<int,int> m;
        for(i=0;i<n;i++)
            m[nums[i]]=i+1;
        for(i=0;i<n;i++)
            if(m[target-nums[i]] && m[target-nums[i]]!=m[nums[i]])
                break;

        vector<int> ans{m[nums[i]],m[target-nums[i]]};
        return ans;
    }
};
