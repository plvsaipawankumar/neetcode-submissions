class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> largest_num;
        vector<int> ans;
        int i,n=nums.size();
        for(i=0;i<k;i++){
            largest_num.push({nums[i],i});
        }
        ans.push_back(largest_num.top().first);
        for(i=k;i<n;i++)
        {
            largest_num.push({nums[i],i});
            cout<<largest_num.top().first<<endl;
            while(!largest_num.empty() && largest_num.top().second<=(i-k))
                largest_num.pop();
            ans.push_back(largest_num.top().first);
        }
        return ans;
    }
};
