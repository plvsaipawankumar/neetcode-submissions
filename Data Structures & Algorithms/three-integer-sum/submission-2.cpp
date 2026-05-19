class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int total=0,i,j,k,n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(i=0;i<n-1;i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1])continue;
            j=i+1;
            k=nums.size()-1;
            while(j<k)
            {
                total = nums[i]+nums[j]+nums[k];
                if(total==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                }
                else if(total<0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
