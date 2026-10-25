class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,n=nums.size(),ans=0;
        map<int,int> sequence;
        for(i=0;i<n;i++){
            if(sequence[nums[i]])continue;
            sequence[nums[i]] = sequence[nums[i]-1]+sequence[nums[i]+1]+1;
            sequence[nums[i]-sequence[nums[i]-1]]=sequence[nums[i]];
            sequence[nums[i]+sequence[nums[i]+1]]=sequence[nums[i]];
            ans=max(ans,sequence[nums[i]]);
            cout<<nums[i]<<" "<<sequence[nums[i]]<<endl; 
        }
        return ans;
    }
};
