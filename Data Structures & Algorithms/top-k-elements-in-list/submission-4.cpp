class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i,n = nums.size();
        map<int,int> count;
        for(i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        priority_queue<pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> heap;
        for(auto & entry : count)
        {
            heap.push({entry.second,entry.first});
            if(heap.size()>k)
            {
                heap.pop();
            }
        }
        vector<int>ans;
        for(i=0;i<k;i++)
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
