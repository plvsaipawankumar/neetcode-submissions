class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i,j,max_value=INT_MIN,n=nums.size(),ans=1,lcs=1;
        if(n==0)return 0;
        map<int,int> m;
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        auto it = m.begin();
        int prev =it->first;++it;
        for(;it!=m.end();++it)
        {
            if(it->first != (prev + 1) )
            {
                ans = max(ans,lcs);
                lcs=1;
            }
            else
                lcs++;
            prev = it->first;
        }
        return max(ans,lcs);
    }
};
