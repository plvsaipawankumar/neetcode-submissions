class Solution {
public:
static bool sortbysecdesc(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second>b.second;
}

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i,n=nums.size();
        vector<int> ans;
        vector<pair<int,int>> count;
        map<int,int> m;
        for(i=0;i<n;i++)
            m[nums[i]]++;

        for(const auto& pr :m)
            count.push_back({pr.first,pr.second});

        sort(count.begin(),count.end(),sortbysecdesc);

        for(i=0;i<k;i++)
            ans.push_back(count[i].first);

        return ans;
    }
};
