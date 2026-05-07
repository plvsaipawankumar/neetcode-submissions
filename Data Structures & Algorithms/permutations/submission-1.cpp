class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> unique_ans;
    void permutation(vector<int> part,vector<int> given,map<int,int> m,int size)
    {
        if(part.size()==size)
        {
            int i,n=size;
            for(i=0;i<n;i++)
                cout<<part[i]<<" ";
            cout<<endl;
            ans.push_back(part);
            return ;
        }
        int i,n=size;
        for(i=0;i<n;i++)
        {
            if(m[given[i]])continue;
            part.push_back(given[i]);
            m[given[i]]++;
            permutation(part,given,m,size);
            m[given[i]]--;
            part.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int i,j=0, n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> part;
        map<int,int> m;
        for(i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        permutation(part,nums,m,n);
        for(auto it = unique_ans.begin();it!=unique_ans.end();it++)
            ans.push_back(*it);
        return ans;
    }
};
