class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int i,j=0,n=nums.size();
        for(i=0;i<n;i++)
        {
            while(!dq.empty() && dq.back()<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(nums[i]);
            if((i-j+1)==k)
            {
                ans.push_back(dq.front());
                if(dq.front()==nums[j])
                    dq.pop_front();
                j++;
            }
        }
        return ans;
    }
};
