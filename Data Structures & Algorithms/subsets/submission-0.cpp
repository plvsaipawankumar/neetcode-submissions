class Solution {
private :
    int size;
public:
    vector<vector<int>> ans;
    void subset(vector<int> nums,vector<int> sub,int i)
    {
        if(i>=size)
        {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subset(nums,sub,i+1);
        sub.pop_back();
        subset(nums,sub,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        vector<int> sub;
        subset(nums,sub,0);
        return ans;
    }
};
