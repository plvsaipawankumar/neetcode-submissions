class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i;
        map<int,int> m;
        for(i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==1)
                return true;
            m[nums[i]] = 1;
        }
        return false;
    }
};
