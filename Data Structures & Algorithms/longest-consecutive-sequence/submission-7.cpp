class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,n=nums.size(),ans=0;
        map<int,int> lenght;
        for(i=0;i<n;i++){
            if(lenght[nums[i]])
                continue;
            lenght[nums[i]]=lenght[nums[i]-1]+lenght[nums[i]+1]+1;
            lenght[nums[i]-lenght[nums[i]-1]] = lenght[nums[i]];
            lenght[nums[i]+lenght[nums[i]+1]] = lenght[nums[i]];
            ans= max(ans,lenght[nums[i]]);
        }
        return ans;
    }
};
