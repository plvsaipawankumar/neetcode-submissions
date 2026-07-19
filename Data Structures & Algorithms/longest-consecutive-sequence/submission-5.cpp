class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> store ;
        int ans=0;
        for(int num:nums)
        {
            if(store[num])
                continue;
            store[num]= store[num-1]+store[num+1]+1;
            store[num - store[num-1]] = store[num];
            store[num+store[num+1]] = store[num];
            ans= max(ans,store[num]);
        }
        return ans;
    }
};
