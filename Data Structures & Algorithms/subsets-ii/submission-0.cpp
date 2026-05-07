class Solution {
public:
    set<vector<int>> unique;
    void subset(vector<int> part,vector<int> nums,int it)
    {
        if(it>=nums.size())
        {
            unique.insert(part);
            return ;
        }
        part.push_back(nums[it]);
        it++;
        subset(part,nums,it);
        part.pop_back();
        subset(part,nums,it);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        int i,n=nums.size();
        sort(nums.begin(),nums.end());
        subset({},nums,0);
        for(auto it=unique.begin();it!=unique.end();it++)
            ans.push_back(*it);
        return ans;
    }
};
