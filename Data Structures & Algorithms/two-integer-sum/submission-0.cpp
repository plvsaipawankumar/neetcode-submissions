class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,pair<int,int>,int> m;
        vector<int> result;
        bool brk=false;
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            for (j=i+1;j<nums.size();j++)
            {
                if((target-nums[i])==nums[j])
                {
                    result.push_back(i);
                    result.push_back(j);
                    brk=true;
                    break;
                }
            }
            if(brk==true)break;
        }
        return result;
    }
};
