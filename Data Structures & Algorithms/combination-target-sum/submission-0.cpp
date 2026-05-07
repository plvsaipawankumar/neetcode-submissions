class Solution {
private:
    int desired=0;
public:
    vector<vector<int>> ans;
    void validSum(vector<int> part,int sum,int index,vector<int> given)
    {
        if(sum>desired || index>=given.size())
            return;
        if(sum==desired)
        {
            ans.push_back(part);
            return ;
        }
        validSum(part,sum,index+1,given);
        part.push_back(given[index]);
        validSum(part,sum+given[index],index,given);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        desired = target;
        vector<int> part;
        validSum(part,0,0,nums);
        return ans;
    }
};
