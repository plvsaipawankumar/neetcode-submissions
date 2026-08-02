class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i,n=nums.size();
        priority_queue<pair<int,int>> pq;
        for(i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        for(i=k;i<n;i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<=(i-k))
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
